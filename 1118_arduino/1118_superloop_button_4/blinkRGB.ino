
//RGB는 삼색으로 빨강, 초록, 파랑이 있다.
long blinkRGB_previousMillis[3] = {0, 0, 0};
long blinkRGB_interval[3] = {1000, 2000, 3000};

int blinkRGB_ledPin[3] = {12, 7, 8};
int blinkRGB_ledState[3] = {LOW, LOW, LOW};

void blinkRGB_setup() {
  //pinMode 초기화
  for (int i=0; i<3; i++) {
    pinMode(blinkRGB_ledPin[i], OUTPUT);
  }
}

void blinkRGB_loop() {
  //millis()함수를 호출하여 currentMillis에 넣어준다.
  //unsigned 양수이다.
  unsigned long currentMillis = millis();

  for(int i=0; i<3; i++) {
    if(currentMillis - blinkRGB_previousMillis[i] >= blinkRGB_interval[i]) {
      blinkRGB_previousMillis[i] = currentMillis;
      
      if(blinkRGB_ledState[i] == LOW)
          blinkRGB_ledState[i] = HIGH;
        else 
          blinkRGB_ledState[i] = LOW;

          digitalWrite(blinkRGB_ledPin[i], blinkRGB_ledState[i]);
    }
  }
  
}
