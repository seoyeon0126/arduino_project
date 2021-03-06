void setup() {
  blink_setup();//함수사용
  fading_setup();
}

void loop() {
  blink_loop();
  fading_loop();
}

int blink_ledState = LOW;//변수
long blink_previousMillis = 0;
long blink_interval = 1000;

void blink_setup() {//함수선언
  pinMode(13, OUTPUT);
}

void blink_loop() {//함수선언
  unsigned long currentMillis = millis();
  
  if(currentMillis - blink_previousMillis >= blink_interval) {
	blink_previousMillis = currentMillis;

	if(blink_ledState == LOW) 
	  blink_ledState = HIGH;
	else
	  blink_ledState = LOW;
	  
	digitalWrite(13, blink_ledState);
  }
}

int fading_ledPin = 11;
int fadeValue = 0;
int fadeDir = 1;
long fading_previousMillis = 0;
long fading_interval = 30;//3초주기

void fading_setup() {}

void fading_loop() {
  unsigned long currentMillis = millis();

  if(currentMillis - fading_previousMillis >= fading_interval) { 
	fading_previousMillis = currentMillis;//long fading_interval = 30;

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
