int ledState = LOW;

long blink_previousMillis = 0;//LED상태가 바뀐 최근시간 저장변수
long blink_interval = 1000;//설정간격을 초기화하고 설정주기를 변경

const int blink_buttonPin = 4;
int blink_buttonState = 0;

void blink_setup() {
  pinMode(13, OUTPUT);
  pinMode(blink_buttonPin, INPUT);
}

void blink_loop() {
  blink_buttonState = digitalRead(blink_buttonPin);
  if(blink_buttonState == LOW) {
    digitalWrite(13, LOW);
    return;
  }
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
