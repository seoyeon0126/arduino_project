#include <Arduino_FreeRTOS.h>
#include <semphr.h>
//대체문자 : *=>모든문자열 ?=>한개문자
//상수선언문

const char* t1_arg = "| \n";
const char* t2_arg = " |\n";

void setup() {//한번 실행하는 설정초기화
  Serial.begin(115200);

  //태스크 생성 (1. 수행할 함수, 2. 태스크이름, 3. 사용할 스택크기, 4. 수행시 넘겨줄 인자, 5. 숫자가높으면 먼저 우선순위 6. 태스크 핸들러)
  xTaskCreate( t_main, NULL, configMINIMAL_STACK_SIZE, (void *)t1_arg, 1, NULL);//우선순위가 낮은건 실행이 안 되는 기아상태가 된다
  xTaskCreate( t_main, NULL, configMINIMAL_STACK_SIZE, (void *)t2_arg, 2, NULL);//우선순위 인 것만 실행이 된다.

  //OS시작
  vTaskStartScheduler();

  //while()은 무한루프로 설정하여 태스크 함수 정의를 한다.
  while(true); 
}

//t_main정의
void t_main(void *arg) {
  const char* t_arg = (const char*) arg;
      while(true) {
          //태스크간의 공유영역 문제 해결( | | ) noInterrupts();를 사용 하면 ( | |이 없어짐)
          noInterrupts();//인터럽트 중지
          Serial.print(t_arg);
          interrupts();//인터럽트 실행

          //우선순위(기아상태) 해결을 위해FreeRTOS에서 제공해 주는 vTaskDelay(인자는 틱의 개수)를 사용하여 약0.25초 지연
          //portTICK_PERIOD_MS인자는 틱의 주기를 나타내고, 아두이노의 FreeRTOS의 경우 16입니다.
          //인터럽트에 의해 틱 주기 16밀리초, 그래서 계산(250/ portTICK_PERIOD_MS)=15틱
          //vTaskDelay()함수는 타이머대기큐로 옮겨져 대기상태로 약 0.25초있다가 CPU처리큐로 옮겨져 수행
          
          vTaskDelay(250/ portTICK_PERIOD_MS);
      }
    }


void loop() {

}
