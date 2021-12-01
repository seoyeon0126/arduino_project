#include <ESP8266WiFi.h>//wifi기능사용
#include <ESP8266WebServer.h>//webserver설정하고 클라이언트의 HTTP요청을 처리하기 위해

const char* ssid = "KT_GiGA_5G_Wave2_8689";//인터넷공유기이름
const char* passwd = "ekc29xb886";//공유기비밀번호

const int HTTP_PORT = 80;//웹서버의  기본포트 80입니다.
ESP8266WebServer webServer(HTTP_PORT);

uint8_t ledESP12 = D0; //16도 가능
uint8_t ledNodeMCU = D4; //2도 가능

const int LED_ON = LOW;
const int LED_OFF = HIGH;
bool ledESP12_ON = false;
bool ledNodeMCU_ON = false;

void setup() {
  Serial.begin(115200);
  pinMode(ledESP12, OUTPUT);
  pinMode(ledNodeMCU, OUTPUT);

  // 공유기에 연결하기
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, passwd);
  
  Serial.print("\nConnecting to ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {//연결되는 동안 .을 찍는다.
	Serial.print('.');
	delay(500);
  }
  Serial.println();  
  Serial.print("connected!, address=");
  Serial.println(WiFi.localIP());//IP주소를 받는다.

  // HTTP 요청 처리함수 등록하기 : 최상위(/)경로에 대한 요청이 웹사이트로 전달
  webServer.on("/", handle_OnConnect);
  webServer.on("/led1on", handle_led1on);
  webServer.on("/led1off", handle_led1off);
  webServer.on("/led2on", handle_led2on);
  webServer.on("/led2off", handle_led2off);
  webServer.onNotFound(handle_NotFound);
  	  
  webServer.begin(); // 웹서버 시작하기 

  Serial.print("HTTP server ready! Use 'http://");
  Serial.print(WiFi.localIP());
  Serial.printf("' to connect\n");
}

void loop() {
  webServer.handleClient();
  
  if(ledESP12_ON)
	digitalWrite(ledESP12, LED_ON);
  else
	digitalWrite(ledESP12, LED_OFF);
  
  if(ledNodeMCU_ON) 
	digitalWrite(ledNodeMCU, LED_ON);
  else
	digitalWrite(ledNodeMCU, LED_OFF);
}

void handle_OnConnect() {//ledESP12_ON, ledNodeMCU_ON 값에 따라 시리얼 모니터에 램프상태출력
  if(ledESP12_ON) Serial.print("GPIO16 Status: ON | ");
  else Serial.print("GPIO16 Status: OFF | ");
  
  if(ledNodeMCU_ON) Serial.print("GPIO2 Status: ON");
  else Serial.print("GPIO2 Status: OFF");
  
  Serial.println();
  
  String html = SendHTML(ledESP12_ON, ledNodeMCU_ON);//HTML페이지를 동적으로 생성
  webServer.send(200, "text/html", html); 
  //HTML내용을 클라이언트로 보냅니다. 응답하는 OK는 200이다.
  //content type이 "text/html" 이다
  //클라이언트로 보낼 HTML내용
}

void handle_led1on() {//GPI016 켜기
  ledESP12_ON = true;
  Serial.println("GPIO16 Status: ON");
  
  String html = SendHTML(ledESP12_ON, ledNodeMCU_ON);
  webServer.send(200, "text/html", html); 
}

void handle_led1off() {//GPI016 끄기
  ledESP12_ON = false;
  Serial.println("GPIO16 Status: OFF");
  
  String html = SendHTML(ledESP12_ON, ledNodeMCU_ON);
  webServer.send(200, "text/html", html); 
}

void handle_led2on() {//GPIO2 켜기
  ledNodeMCU_ON = true;
  Serial.println("GPIO2 Status: ON");
  
  String html = SendHTML(ledESP12_ON, ledNodeMCU_ON);
  webServer.send(200, "text/html", html); 
}

void handle_led2off() {//GPIO2 끄기 
  ledNodeMCU_ON = false;
  Serial.println("GPIO2 Status: OFF");
  
  String html = SendHTML(ledESP12_ON, ledNodeMCU_ON);
  webServer.send(200, "text/html", html); 
}

void handle_NotFound(){
  webServer.send(404, "text/plain", "Not found");
}

//HTML과 CSS를 작성하여 화면구성을 설정
String SendHTML(bool led1_on, uint8_t led2_on){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" ";//viewport : 어떤 웹브라우저에서도 응답하게 합니다.
  ptr +="content=\"width=device-width, ";
  ptr +="initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>LED Control</title>\n";
  ptr +="<style>html { font-family: Helvetica; ";//CSS를 이용하여 버튼과 웹페이지의 모양을 설정
  ptr +="display: inline-block; margin: 0px auto; ";
  ptr +="text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;";
  ptr +="margin: 50px auto 30px;} h3 {color: #444444;";
  ptr +="margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;";
  ptr +="background-color: #1abc9c;border: none;";
  ptr +="color: white;padding: 13px 30px;";
  ptr +="text-decoration: none;font-size: 25px;";
  ptr +="margin: 0px auto 35px;cursor: pointer;";
  ptr +="border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #1abc9c;}\n";
  ptr +=".button-on:active {background-color: #16a085;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>NodeMCU Web Server</h1>\n";
  
  if(led1_on) {
	ptr +="<p>LED1 Status: ON</p>";
	ptr +="<a class=\"button button-off\" ";
	ptr +="href=\"/led1off\">OFF</a>\n";
  } else {
	ptr +="<p>LED1 Status: OFF</p>";
	ptr +="<a class=\"button button-on\" ";
	ptr +="href=\"/led1on\">ON</a>\n";
  }

  if(led2_on) {
	ptr +="<p>LED2 Status: ON</p>";
	ptr +="<a class=\"button button-off\" ";
	ptr +="href=\"/led2off\">OFF</a>\n";
  } else {
	ptr +="<p>LED2 Status: OFF</p>";
	ptr +="<a class=\"button button-on\" ";
	ptr +="href=\"/led2on\">ON</a>\n";
  }

  ptr +="</body>\n";
  ptr +="</html>\n";
  
  return ptr;
}
