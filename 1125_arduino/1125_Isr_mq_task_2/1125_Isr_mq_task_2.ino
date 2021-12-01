#include <Arduino_FreeRTOS.h>
#include <semphr.h>
//세마포어
#define BUF_SIZE 16//버퍼의 크기를 16으로 지정
int buf[BUF_SIZE] = {0,};//버퍼의 크기만큼 배열로선언
int front = 0;//메시지큐가 채워져있는 버퍼의 시작위치
int rear = 0;//메시지큐가 비어있는 버퍼의 시작위치
int how_many = 0;//큐에 들어와 있는 데이터개수
SemaphoreHandle_t button_pressed = NULL;//세마포어 핸들 선언을 NULL

void setup() {
  Serial.begin(115200);

  attachInterrupt(digitalPinToInterrupt(2), buttonIsr, RISING);
  //xSemaphoreCreateCounting함수는 카운팅 세마포어는 보호하고자하는 자원의 개수2개이상일때 사용
  //인수는 1. 최대증가(BUF_SIZE=>16) 2. 초기자원의 개수(0)
  button_pressed = xSemaphoreCreateCounting(BUF_SIZE, 0);
  //태스크 생성
  xTaskCreate(tbutton_main, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
  //OS시작
  vTaskStartScheduler();
  //while()은 무한루프로 설정하여 태스크 함수를 정의 한다.
  while(true);
}

void buttonIsr( void ) {
  static int DevRegister = 0;
  int DataToSend = 0;
  BaseType_t xHigherPriorityTaskWoken = pdFALSE;

  DevRegister ++;//가상장치레지스터동작시키다. 1씩증가하도록.

  DataToSend = DevRegister;//태스크에 보내질 데이터에 디바이스레지스터값을 대입

  Serial.print( "isr(" );
  Serial.print(DataToSend);
  Serial.print( ") => " );

  if(how_many<BUF_SIZE) {//버퍼보다 큐에 들어있는 데이터가 작으면 빈 버퍼가 있다
      buf[rear] = DataToSend;//빈 버퍼 시작위치에 DataToSend를 채우고
      rear++;//한칸이동 (주소이동)
      if(rear >= BUF_SIZE) { rear = 0; }//버퍼범위가 넘어가면 버퍼의 처음위치로 초기화
      how_many ++;//버퍼에 찬 데이터 개수를 증가
  }
  //카운팅세마포어 변수증가하면서 pdTRUE
  xSemaphoreGiveFromISR(button_pressed, &xHigherPriorityTaskWoken);

  if( xHigherPriorityTaskWoken ) {//우선순위로 깨어져있는 태스크가 참 이되면
    taskYIELD();//대기태스크에서 태스크메인함수(tbutton_main)으로 이동
  }
}//end buttonIsr 함수

//tbutton_main 함수정의
void tbutton_main( void *arg ) {
  
  int DataToReceive = 0;//메시지큐에서 읽어온 데이터를 저장변수
  //xBlockTime은 틱으로 200밀리초 저장 하고
  //계산시 아두이노의 틱의 주기인 16으로 나눈다. => 200/16 = 12틱이 됩니다.
  const TickType_t xBlockTime = pdMS_TO_TICKS( 200 );

  while (true) {

    if(xSemaphoreTake(button_pressed, xBlockTime ) == pdTRUE ) {
      noInterrupts();
      if(how_many > 0) {//데이터의 개수값이 0보다 크면 도착할 데이터가 있다
        DataToReceive = buf[front];
        front ++;//데이터가 있는 버퍼의 시작위치를 증가
        if(front >= BUF_SIZE) { front = 0; }//데이터가 있는 버퍼의 시작위치 범위를 넘기면 버퍼의 처음 위치로 초기화한다.
        how_many --;//버퍼에 있는 데이터가 태스크의 메세지로 이동하면 감소시킨다.
      }
      interrupts();

      noInterrupts();//buttonIsr함수의 Serial.print()와 충돌하지 않도록 한다.
      Serial.print( "tbutton( ");
      Serial.print(DataToReceive);//메시지 큐로부터 읽은 데이터를 출력
      Serial.print( " ) " );
      Serial.println();
      interrupts();
    }
  }
}

void loop() {

}
