//아날로그 출력하기
int ledESP12 = D0;
int ledNodeMCU = D4;

void setup() {
  
}

void loop() {
  for(int i = 1023; i>=0; i--) {
    analogWrite(ledESP12, i);
    analogWrite(ledNodeMCU, i);
    delay(10);
  }
}
