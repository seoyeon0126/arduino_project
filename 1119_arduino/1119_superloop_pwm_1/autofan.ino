const int analogInPin = A1;//Read는 InPut
const int analogOutPin = 6;//Write는 OutPut

int sensorValue = 0;
int outputValue = 0;

//주기적 작업
long autofan_previousMillis = 0;
long autofan_interval = 2;

void autofan_setup() {
  
}

void autofan_loop() {
  unsigned long currentMillis = millis();

  if(currentMillis - autofan_previousMillis >= autofan_interval) {
    autofan_previousMillis = currentMillis;

    sensorValue = analogRead(analogInPin);
    outputValue = map(sensorValue, 0, 1023, 0, 255);
    analogWrite(analogOutPin, outputValue);
  }
}
