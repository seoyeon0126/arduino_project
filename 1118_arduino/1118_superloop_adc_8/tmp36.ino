int tmp36sensorPin = A1;//온도센서 연결된 아날로그 입력핀
int tmp36ledPin = 13;//LED핀번호
int tmp36sensorValue = 0;//온도센서(가변저항)의 입력 값 저장변수
long tmp36_previousMillis = 0;//이전밀리초값 초기값(주기적인 작업)
long tmp36_interval = 0;//간격

int tmp36sensor_ledState = 1;//LED의 상태

void tmp36sensor_setup() {
  pinMode(tmp36ledPin, OUTPUT);
}

void tmp36sensor_loop() {
  //주기적인 작업
  unsigned long currentMillis = millis();

  if(currentMillis - tmp36_previousMillis >= tmp36_interval) {//주기
    tmp36_previousMillis = currentMillis;

    if(tmp36sensor_ledState != 0) {
      tmp36sensorValue = analogRead(tmp36sensorPin);//아날로그값을 입력한다
      tmp36_interval = tmp36sensorValue;//주기에 대입한다.
    }

    digitalWrite(tmp36ledPin, tmp36sensor_ledState);
    tmp36sensor_ledState = !tmp36sensor_ledState;
    
  }
}
