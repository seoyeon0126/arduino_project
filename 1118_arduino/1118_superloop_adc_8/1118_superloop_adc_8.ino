void setup() {
  serial_setup();//시리얼 기능을 설정
  potentiometer_setup();//가변저항 기능 설정함수
  tmp36sensor_setup();
  photosensor_setup();
}

void loop() {
  serial_loop();//시리얼 입력을 처리
  potentiometer_loop();//가변저항 입력처리 함수
  tmp36sensor_loop();
  photosensor_loop();
}
