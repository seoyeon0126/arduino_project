#include <TimerOne.h>

void setup() {
  Serial.begin(115200);
  Timer1.initialize(1000);
  Timer1.attachInterrupt( timerIsr );
}

void loop() {
  unsigned long currentMillis = get_millis();
  Serial.println(currentMillis);
}

unsigned long timer1_millis = 0;

void timerIsr() {
  timer1_millis ++;
}

unsigned long get_millis(void) {
  return timer1_millis;
}
