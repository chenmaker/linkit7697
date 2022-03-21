#include <LWiFi.h>
#include "MCS.h"

char _lwifi_ssid[] = "szx";
char _lwifi_pass[] = "0f9u7c8k";

MCSDevice mcs("DbN6wi0e", "E1rbt0pgaCHFGODm");
MCSControllerOnOff MySwitch("ms");
MCSControllerOnOff MySwitch1("ms1");
int led=2;
void setup()
{
  Serial.begin(9600);

  mcs.addChannel(MySwitch);
  mcs.addChannel(MySwitch1);
  Serial.println("Wi-Fi 開始連線");
  while (WiFi.begin(_lwifi_ssid, _lwifi_pass) != WL_CONNECTED) { delay(1000); }
  Serial.println("Wi-Fi 連線成功");
  while(!mcs.connected()) { mcs.connect(); }
  Serial.println("MCS 連線成功");
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  while (!mcs.connected()) {
    mcs.connect();
    if (mcs.connected()) { Serial.println("MCS 已重新連線"); }
  }
  mcs.process(100);

  if (MySwitch.updated()) {
    Serial.print("控制通道更新 :");
    Serial.println(MySwitch.value());

    if (MySwitch.value()) {
      digitalWrite(LED_BUILTIN, HIGH);

    } else {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }  
  if (MySwitch1.updated()) {
    Serial.print("控制通道更新1 :");
    Serial.println(MySwitch1.value());

    if (MySwitch1.value()) {
      digitalWrite(led, HIGH);

    } else {
      digitalWrite(led, LOW);
    }
  }
  delay(1000);
}
