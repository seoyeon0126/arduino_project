const int buttonFLASH = D3;

void setup() {
  Serial.begin(115200);
  pinMode(buttonFLASH, INPUT);
}

void loop() {
  int button = digitalRead(buttonFLASH);
  Serial.println(button);
  
}
