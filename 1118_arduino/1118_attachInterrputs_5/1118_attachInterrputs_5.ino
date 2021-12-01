int pin = 11;
volatile int state = LOW;

void setup() {
  pinMode(pin, OUTPUT);
  //attachInterrupt 함수를 호출하여 2번 핀에 해당하는 외부인터럽트에 대한 처리 함수등록
  //digitalPinToInterrput는 핀에 해당하는 외부 인터럽트 번호를 리턴해주는 함수
  //RISING 상수는 2번 핀 입력값이 LOW HIGH로 바뀌는 순간
  //buttonIsr 인터럽트 처리함수를 하드웨어적으로 호출하라는 의미
    attachInterrupt(digitalPinToInterrupt(2), buttonIsr, RISING);
}

void loop() {
  digitalWrite(pin, state);
}

void buttonIsr() {
  state = !state; 
}
