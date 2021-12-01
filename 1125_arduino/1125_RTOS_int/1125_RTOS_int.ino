#include <Arduino_FreeRTOS.h>
#include <semphr.h>

void setup() {
  Serial.begin(115200);

  //외부인터럽트 : 인수는 핀번호, 수행할 함수, 함수실행 LOW HIGH
  attachInterrupt(digitalPinToInterrupt(2), buttonIsr, RISING);

  xTaskCreate( tbutton_main, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL );

  vTaskStartScheduler();

  while( true );
}

void buttonIsr( void ) {
  
  noInterrupts();
  Serial.print(" > \n");
  interrupts();
  
}

void tbutton_main( void *arg) {

  while( true ) {
    noInterrupts();//인터럽트 중지
    Serial.print(" | \n");
    interrupts();//인터럽트실행

    vTaskDelay( 100 / portTICK_PERIOD_MS );
  }
}

void loop() {

}
