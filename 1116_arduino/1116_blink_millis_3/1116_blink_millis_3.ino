const int ledPin =  13; 

int ledState = LOW;//LED가 꺼짐
long previousMillis = 0;//LED상태가 바뀐 최근시간 저장변수

long interval = 1000;//설정간격을 초기화하고 설정주기를 변경

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);//출력    
}

void loop() {
  unsigned long currentMillis = millis();//양수의 값을 시간
  Serial.println(currentMillis);
  
  if(currentMillis - previousMillis >= interval) {//현재초-이전초 >= 간격
	previousMillis = currentMillis;   

   if (ledState == LOW)
	  ledState = HIGH;
	else
	  ledState = LOW;

	digitalWrite(ledPin, ledState);
  }
}
