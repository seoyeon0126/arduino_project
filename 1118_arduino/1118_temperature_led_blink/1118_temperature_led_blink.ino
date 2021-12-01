int sensorPin = A1;
int ledPin = 13;
int sensorValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.print(" seonsor = " );
  Serial.println(sensorValue);

  float voltage = (sensorValue/1024.0) * 5.0; //전압 = 전류 * 저항
  Serial.print(", volts = " );
  Serial.print(voltage);

  float temperature = (voltage - .5 ) * 100;
  Serial.print(", degrees C = " );
  Serial.println(temperature);

  digitalWrite(ledPin, HIGH);
  delay(sensorValue);
  digitalWrite(ledPin, LOW);
  delay(sensorValue);

  
}
