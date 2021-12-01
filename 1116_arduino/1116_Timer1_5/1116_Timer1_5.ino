#include <TimerOne.h>

void setup() {
  Serial.begin(115200);
  Timer1.initialize(1000);
  Timer1.attachInterrupt( timerIsr );
}

void loop() {
  noInterrupts();//인터럽트 지연
  Serial.println(" | ");
  interrupts();//인터럽트 감지
}

void timerIsr() {
  Serial.println(" ] ");
  //digitalWrite(13, digitalRead(13)^1);
}
