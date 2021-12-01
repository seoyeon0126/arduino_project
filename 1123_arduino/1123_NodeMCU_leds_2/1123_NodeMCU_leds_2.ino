//와이파이에 있는 램프의 핀번호 P0(16),  D4(2) 할당

const int ledESP12 = D0;
const int ledNodeMCU = D4;
//LED의 ON, OFF
const int LED_ON = LOW;
const int LED_OFF = HIGH;

void setup() {
  pinMode(ledESP12, OUTPUT);
  pinMode(ledNodeMCU, OUTPUT);
}

void loop() {
  //켜기
  digitalWrite(ledESP12, LED_ON);
  digitalWrite(ledNodeMCU, LED_ON);
  delay(1000);

  //끄기
  digitalWrite(ledESP12, LED_OFF);
  digitalWrite(ledNodeMCU, LED_OFF);
  delay(1000); 
}
