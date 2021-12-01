#include <SoftwareSerial.h>

int BT_TX = 2;//송신->1
int BT_RX = 3;//수신->0 보드의 0RX 1TX를 블루투스로 사용하면 보드와 PC연동을 못한다.

//SoftwareSerial (RX, TX) 형식으로 블루투스 모듈과 교차하여 연결
SoftwareSerial BTSerial(BT_TX, BT_RX);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  if(BTSerial.available()) {//블루투스모듈 -> 아두이노 -> 시리얼모니터
    Serial.write(BTSerial.read());
  }

  if(Serial.available()) {//시리얼모니터 -> 아두이노 -> 블루투스모듈
    BTSerial.write(Serial.read());
  }
}
