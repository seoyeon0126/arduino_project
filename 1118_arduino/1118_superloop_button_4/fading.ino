int fading_ledPin = 11;
int fadeValue = 0;
int fadeDir = 1;

long fading_previousMillis = 0;
long fading_interval = 30;

int buttonToggle = 0;//토글

void fading_setup() {
  //인터럽트함수 호출
  attachInterrupt(digitalPinToInterrupt(2), buttonIsr, RISING);
}

void buttonIsr() {//인터럽트 처리함수
  buttonToggle = !buttonToggle;
}

void fading_loop() {
  if(buttonToggle==0) {
    analogWrite(fading_ledPin, 0);
    return;
  }
  unsigned long currentMillis = millis();
    if(currentMillis - fading_previousMillis >= fading_interval) {
      fading_previousMillis = currentMillis;

    if(fadeDir == 1) { 
    if(fadeValue <= 255) {        
    fadeValue += 5;
    
    if(fadeValue > 255) {          
      fadeValue = 255;
      fadeDir = 0;
    }  
   }
   
  } else { 
    if(fadeValue >= 0) {
    fadeValue -= 5;
    if(fadeValue < 0) {
      fadeValue = 0;
      fadeDir = 1;          
    }
    }
  }
  analogWrite(fading_ledPin, fadeValue);
}
}
