//사용자 입력기능추가

int melody_en = 1;
int autocurtain_en = 1;
int autofan_en = 1;

void setup() {//초기값 설정 한번 실행
  serial_setup();
  melody_setup();
  autocuratin_setup();
  autofan_setup();
}

void loop() {//처리를 하면 무한루프
   serial_loop();
   if(melody_en == 1)
   melody_loop();
   if(autocurtain_en == 1)
   autocuratin_loop();
   if(autofan_en == 1)
   autofan_loop();
}
