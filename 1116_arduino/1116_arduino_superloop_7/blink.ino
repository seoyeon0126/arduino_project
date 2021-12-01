int ledState = LOW;

long blink_previousMillis = 0;//LED상태가 바뀐 최근시간 저장변수
long blink_interval = 1000;//설정간격을 초기화하고 설정주기를 변경

void blink_setup() {
  pinMode(13, OUTPUT);
}

void blink_loop() {
  unsigned long currentMillis = millis();

  if(currentMillis - blink_previousMillis >= blink_interval) {
    blink_previousMillis = currentMillis;

    if(ledState == LOW)
      ledState = HIGH;
      else 
      ledState = LOW;

      digitalWrite(13, ledState);

  }
}
