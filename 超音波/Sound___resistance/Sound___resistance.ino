#include <LWiFi.h>
#include "MCS.h"

int cm=15;
int ch=14;
char _lwifi_ssid[] = "TP-Link_A3B4";
char _lwifi_pass[] = "83571619";

MCSDevice mcs("DHEoY0It", "BbG1W0uLDZiTFhJh");
MCSDisplayInteger r("D1");
MCSDisplayInteger s("S1");

void setup() 
{
  Serial.begin(9600);
  mcs.addChannel(r);
  mcs.addChannel(s);
  Serial.println("Wi-Fi 開始連線");
  while (WiFi.begin(_lwifi_ssid,_lwifi_pass) !=WL_CONNECTED) {delay(1000);}
  Serial.println("Wi-Fi 連線成功");
  while (!mcs.connected()) {mcs.connect();}
  Serial.println("MCS 連線成功");
  
}
void loop() {
  while (!mcs.connected()){
      mcs.connect();
      if (mcs.connected()) {  Serial.println("MCS 已重新連線");}
    }
    mcs.process(100);
    r.set(analogRead(ch));
    Serial.print("可變電阻:");
    Serial.println(analogRead(ch));
    s.set(analogRead(cm));
    Serial.print("可變電阻1:");
    Serial.println(analogRead(cm));  
    delay(1000);
}
