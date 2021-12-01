const int digitalPin = 4;//상수선언(const) 후 4번 핀으로 초기화
int digitalValue;//디지털 입력 값을 저장하는 변수

void setup() {
  Serial.begin(115200);

  pinMode(digitalPin, INPUT);
}

void loop() {
  digitalValue = digitalRead(digitalPin);
  Serial.println(digitalValue);
}

//GND = 0 , 5V = 1
