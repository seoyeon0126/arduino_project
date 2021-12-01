#include <Arduino_FreeRTOS.h>
#include <semphr.h>

void setup() {//한번 실행하는 설정초기화
  Serial.begin(115200);

  //태스크 생성 (1. 수행할 함수, 2. 태스크이름, 3. 사용할 스택크기, 4. 수행시 넘겨줄 인자, 5. 우선순위 6. 태스크 핸들러)
  xTaskCreate( t1_main, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
  xTaskCreate( t2_main, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);

  //OS시작
  vTaskStartScheduler();

  //while()은 무한루프로 설정하여 태스크 함수 정의를 한다.
  while(true); 
}

    //t1_main정의
void t1_main(void *arg) {
      while(true) {
          Serial.print("|     \n");
      }
    }

void t2_main(void *arg) {
      while(true) {
          Serial.print("     |\n");
      }
    }


void loop() {

}
