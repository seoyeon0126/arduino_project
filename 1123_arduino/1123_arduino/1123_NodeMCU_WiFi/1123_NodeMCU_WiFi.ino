#include <WiFiManager.h>//와이파이 id와 pw 초기설정하기
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiUdp.h>
#include <ESP8266WebServer.h>
#include <ESP8266WebServerSecure.h>

const char* ssid = " iot_programming_0" ;
const char* passwd = " 12345678 ";

//포트번호 80은 통신포트
const int HTTP_PORT = 80;
ESP8266WebServer webServer(HTTP_PORT);

void setup() {
  Serial.begin(115200);

  //공유기연결하기
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, passwd);

// WiFiManager : 로컬초기화, 일단 작동이 끝나면 더 이상 가지고 있을 필요없다.
//  WiFiManager wifiManager;
//  wifiManager.resetSettings();
//  wifiManager.autoConnect("iot_3", "12345678");

  Serial.print("\nConnecting to ");
//  Serial.println(ssid);

  while(WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.println();
  Serial.print("connected!, address=");
  Serial.print(WiFi.localIP());
}

void loop() {

}
