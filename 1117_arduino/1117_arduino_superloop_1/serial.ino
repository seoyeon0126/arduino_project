//메뉴를 보여주는 함수작성
void showMenu() {
  Serial.println(" 1. Led Blink Enable/Disable " );
  Serial.println(" 2. Led Fading Enable/Disable " );
  Serial.println(" 3. RGB Led Blink Enable/Disable " );
  Serial.println(" 4. RGB Led Fading Enable/Disable " );
}

void serial_setup() {
  Serial.begin(115200);

  showMenu();
}

int userCmd = 0;

void serial_loop() {
  if (Serial.available() > 0) {//데이터도착여부
      userCmd = Serial.read();//도착한데이터 읽기

      Serial.print(" user command: ");
      Serial.println((char) userCmd);

      switch(userCmd) {//토글키 만들기
        case '1' : blink_en = !blink_en; 
          break;
        case '2' : fading_en = !fading_en; 
          break;
        case '3' : blinkRGB_en = !blinkRGB_en; 
          break;
        case '4' : fadingRGB_en = !fadingRGB_en; 
          break;
        default :
          break;
      
      }
  }
}
