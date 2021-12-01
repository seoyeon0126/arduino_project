#include <Arduino_FreeRTOS.h>
#include <semphr.h>
//대체문자 : *=>모든문자열 ?=>한개문자
//상수선언문

const char* t1_arg = "| \n";
const char* t2_arg = " |\n";

void setup() {//한번 실행하는 설정초기화
  Serial.begin(115200);

  //태스크 생성 (1. 수행할 함수, 2. 태스크이름, 3. 사용할 스택크기, 4. 수행시 넘겨줄 인자, 5. 우선순위 6. 태스크 핸들러)
  xTaskCreate( t_main, NULL, configMINIMAL_STACK_SIZE, (void *)t1_arg, 1, NULL);
  xTaskCreate( t_main, NULL, configMINIMAL_STACK_SIZE, (void *)t2_arg, 1, NULL);

  //OS시작
  vTaskStartScheduler();

  //while()은 무한루프로 설정하여 태스크 함수 정의를 한다.
  while(true); 
}

void t_main(void *arg) {
  const char* t_arg = (const char*) arg;
      while(true) {
          //태스크간의 공유영역 문제 해결 noInterrupts();를 사용
          noInterrupts();//인터럽트 중지
          Serial.print(t_arg);
          interrupts();//인터럽트 실행
      }
    }


void loop() {

}
