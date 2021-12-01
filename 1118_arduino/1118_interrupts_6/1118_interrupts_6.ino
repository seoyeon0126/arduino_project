void setup() {
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(2), buttonIsr, RISING);
}

void loop() {
  noInterrupts();
  //buttonIsr함수에서 호출한 Serial.println(" > "); 와 충돌이 생기므로 여기서 인터럽트를 막습니다.
  Serial.println(" | ");
  delay(100);
  interrupts();
  delay(100);
}

void buttonIsr() {
  Serial.println(" > ");
}
