int incomingByte = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {//데이터도착여부
    incomingByte = Serial.read();//도착한데이터 읽기

    Serial.print(" I received: ");
    Serial.println(incomingByte, DEC);
  }
}
