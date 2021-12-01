int ledPin = 11;
void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  delay(2000); 
  
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(ledPin, fadeValue);
    digitalWrite(13, HIGH);
    delay(30);
  }

  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(ledPin, fadeValue);
    digitalWrite(13, LOW);
    delay(30);
  }
}
