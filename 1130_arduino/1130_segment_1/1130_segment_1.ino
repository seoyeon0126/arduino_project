boolean digits[10][8] = {
{1,1,1,1,1,1,0,1}, // 0
{0,1,1,0,0,0,0,1}, // 1
{1,1,0,1,1,0,1,1}, // 2
{1,1,1,1,0,0,1,1}, // 3
{0,1,1,0,0,1,1,1}, // 4
{1,0,1,1,0,1,1,1}, // 5
{1,0,1,1,1,1,1,1}, // 6
{1,1,1,0,0,1,0,1}, // 7
{1,1,1,1,1,1,1,1}, // 8
{1,1,1,1,0,1,1,1}  // 9
};

int inPin = 13;
int btnState = HIGH;

void setup() {
pinMode(inPin, INPUT_PULLUP);  for (int i = 2; i < 13; i++) {
pinMode(i, OUTPUT);
}
randomSeed(analogRead(A0));  digitalWrite(12, LOW);  digitalWrite(11, LOW);  digitalWrite(10, LOW);
}

void loop() {

btnState = digitalRead(inPin);
}
