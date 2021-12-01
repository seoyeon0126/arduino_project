#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  if(BTSerial.available()) {//블루투스모듈 -> 아두이노 -> 시리얼모니터
    char bread = BTSerial.read();

    if (bread == 'a')
      digitalWrite(13, LOW);
    else if (bread == 'b') 
      digitalWrite(13, HIGH);
  }
}
