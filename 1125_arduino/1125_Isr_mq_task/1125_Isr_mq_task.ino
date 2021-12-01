#include <Arduino_FreeRTOS.h>
#include <semphr.h>

//메세지 큐를 이용하여 태스크로 메세지 보내기
QueueHandle_t xQueueButton = NULL;//메세지 큐 핸들을 선언

void setup() {
  Serial.begin(115200);

  //외부인터럽트 : 인수는 핀번호, 수행할 함수, 함수실행 LOW HIGH
  attachInterrupt(digitalPinToInterrupt(2), buttonIsr, RISING);

  //정수형 데이터 16개를 갖는 메세지
  xQueueButton = xQueueCreate( 16, sizeof( int ) );

  //태스크 생성
  xTaskCreate( tbutton_main, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL );

  //OS시작
  vTaskStartScheduler();

  //while()은 무한루프로 설정하여 태스크 함수 정의를 한다.
  while( true );
}

void buttonIsr( void ) {//버튼함수

  static int DevRegister = 0;//가상장치 레지스터변수, static은 정적변수로서 어디서나 공용으로 사용 가능
  int DataToSend = 0;//레지스터로부터 읽어올 데이터 저장메모리변수
  BaseType_t xHigherPriorityTaskWoken = pdFALSE;//우선순위의 태스크가 깨어 있는 지 여부

  DevRegister ++;//가장장치 레지스터동작

  DataToSend = DevRegister;//태스크에 보내질 데이터에 디바이스레지스터값을 대입

  Serial.print(" isr( ");
  Serial.print(DataToSend);
  Serial.print(" ) => ");

  //xQueueSendFromISR함수가 메세지 큐로 읽어온 데이터를 보낸다.
  //xQueueButton : 정수형 데이터 16개를 갖는 메세지
  //DataToSend : 태스크에 보내질 데이터에 디바이스레지스터값을 대입
  //xHigherPriorityTaskWoken : pdFALSE => 우선순위의 태스크가 깨어 있는지 여부
  xQueueSendFromISR(xQueueButton, &DataToSend, &xHigherPriorityTaskWoken);

  if( xHigherPriorityTaskWoken) {//우선순위로 깨어져있는 태스크가 (참) 이 되면
    taskYIELD();//대기태스크에서 태스크메인함수(tbutton_main)로 이동
  }
}

//tbutton_main 함수정의
void tbutton_main( void *arg) {

  int DataToReceive = 0;//메시지큐에서 읽어온 데이터를 저장변수
  //xBlockTime은 틱으로 200밀리초 저장하고
  //계산시 아두이노의 틱의 주기인 16으로 나눈다. ==> 200/16 = 12가 됩니다
  const TickType_t xBlockTime = pdMS_TO_TICKS( 200 );

  while( true ) {

    if (xQueueReceive(xQueueButton, &DataToReceive, xBlockTime) == pdTRUE) {
      
    
    noInterrupts();//buttonIsr함수의 Serial.print()와 충돌하지 않도록 한다.
    Serial.print("tbutton(");
    Serial.print(DataToReceive);//메시지 큐로부터 익어온 데이터를 출력
    Serial.print(")");
    Serial.println();
    interrupts();//인터럽트실행

    vTaskDelay( 100 / portTICK_PERIOD_MS );
    }
  }
}

void loop() {

}
