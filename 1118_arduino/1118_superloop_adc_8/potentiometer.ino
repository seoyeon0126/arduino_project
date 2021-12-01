const int pot_analogInPin = A0;//가변저항에 연결된 입력
const int pot_analogOutPin = 11;//LED에 연결된 핀 

int pot_sensorValue = 0;//가변저항입력값변수
int pot_outputValue = 0;//출력값변수

long pot_previousMillis = 0;//millis()를 이용하여 주기적인 작업 이전 밀리초
long pot_interval = 2;//대기시간 0.002밀리초

void potentiometer_setup() {

}

void potentiometer_loop() {
  unsigned long currentMillis = millis();//millis()함수를 이용하여 현재밀리초를 대입

  if(currentMillis - pot_previousMillis >= pot_interval) {//현재-이전>=간격
    pot_previousMillis = currentMillis;//이전밀리초에 현재밀리초를 대입

    pot_sensorValue = analogRead(pot_analogInPin);
    pot_outputValue = map(pot_sensorValue, 0, 1023, 0, 255);
    analogWrite(pot_analogOutPin, pot_outputValue);

    Serial.print("postentiometer value = ");
    Serial.print(pot_sensorValue);
    Serial.print(", led brightness = ");
    Serial.println(pot_outputValue);
  }
}
