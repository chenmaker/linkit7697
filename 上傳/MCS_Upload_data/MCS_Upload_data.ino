#include <LWiFi.h>
#include "MCS.h"
#include "DHT.h"

int t;
int h;
int ch=14;
char _lwifi_ssid[] = "TP-Link_A3B4";
char _lwifi_pass[] = "83571619";

MCSDevice mcs("DmGGQt6y", "8EcKu0EHkaSdg2bx");
MCSDisplayInteger temp("temp");
MCSDisplayInteger hum("hum");
MCSDisplayInteger change("change");
DHT dht(2, DHT11);

void setup() 
{
  Serial.begin(9600);

  mcs.addChannel(temp);
  mcs.addChannel(hum);
  mcs.addChannel(change);
  Serial.println("Wi-Fi 開始連線");
  while (WiFi.begin(_lwifi_ssid,_lwifi_pass) !=WL_CONNECTED) {delay(1000);}
  Serial.println("Wi-Fi 連線成功");
  while (!mcs.connected()) {mcs.connect();}
  Serial.println("MCS 連線成功");
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  while (!mcs.connected()){
      mcs.connect();
      if (mcs.connected()) {  Serial.println("MCS 已重新連線");}
    }
    mcs.process(100);
    t = dht.readTemperature();
    h = dht.readHumidity();
    temp.set(t);
    hum.set(h);
    change.set(analogRead(ch));
    Serial.print("攝氏溫度:");
    Serial.println(t);
    Serial.print("相對濕度:");
    Serial.println(h);
    Serial.print("可變電阻:");
    Serial.println(analogRead(ch));
    delay(1200);
}
