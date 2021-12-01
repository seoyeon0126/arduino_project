const int analogPin = A0;//상수선언(const) 후 4번 핀으로 초기화
int analogValue;//디지털 입력 값을 저장하는 변수

void setup() {
  Serial.begin(115200);

//  pinMode(analogPin, INPUT);
}

void loop() {
  analogValue = analogRead(analogPin);
  Serial.println(analogValue);
}

//GND = 0 , 5V = 1
