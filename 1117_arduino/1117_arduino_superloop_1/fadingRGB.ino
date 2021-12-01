
//RGB는 삼색으로 빨강, 초록, 파랑이 있다.
long fadingRGB_previousMillis[3] = {0, 0, 0};
long fadingRGB_interval[3] = {30, 60, 90};

int fadingRGB_ledPin[3] = {10, 6, 9};
int fadeRGBValue[3] = {0, 0, 0};
int fadeRGBDir[3] = {1, 1, 1};

void fadingRGB_setup() {
}

void fadingRGB_loop() {
  //millis()함수를 호출하여 currentMillis에 넣어준다.
  //unsigned 양수이다.
  unsigned long currentMillis = millis();

  for(int i=0; i<3; i++) {
    if(currentMillis - fadingRGB_previousMillis[i] >= fadingRGB_interval[i]) {//주기적인 작업
      fadingRGB_previousMillis[i] = currentMillis;

      if(fadeRGBDir[i] == 1) {
        if(fadeRGBDir[i] <= 255) {
          fadeRGBValue[i] += 5;
        if(fadeRGBValue[i] > 255) {
            fadeRGBValue[i] = 255;
            fadeRGBDir[i] = 0;
        }
      }
      } else {
       if(fadeRGBValue >= 0) {
          fadeRGBValue[i] -= 5;
        if(fadeRGBValue[i] < 0) {
            fadeRGBValue[i] = 0;
            fadeRGBDir[i] = 1;
        }
      }
      }
    }
          analogWrite(fadingRGB_ledPin[i], fadeRGBValue[i]);
  }
}
