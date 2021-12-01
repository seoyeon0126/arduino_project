#include <Servo.h>

Servo myservo;

int potpin = A0;
int val;

void autocuratin_setup() {
  myservo.attach(9);
}

void autocuratin_loop() {
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 180);
  myservo.write(val);
  delay(15);
  
}
