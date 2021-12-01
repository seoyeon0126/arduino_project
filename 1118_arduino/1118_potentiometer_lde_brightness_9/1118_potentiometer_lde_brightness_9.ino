const int analogInPin = A0;
const int analogOutPin = 11;
int sensorValue = 0;
int outputValue = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(analogOutPin, outputValue);

  Serial.print(" sensor = " );
  Serial.print(sensorValue);
  Serial.print(" \t output = " );
  Serial.println(outputValue);

  delay(2);
}
