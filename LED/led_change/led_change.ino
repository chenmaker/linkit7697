#include <LBLE.h>
#include <LBLEPeriphral.h>
int item;
LBLEService AService("19B10010-E8F2-537E-4F6C-D104768A1214");
LBLECharacteristicInt ARead("19B10011-E8F2-537E-4F6C-D104768A1214", LBLE_READ | LBLE_WRITE);
void setup() {
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  Serial.begin(9600);
  LBLE.begin();
  while (!LBLE.ready()) {
    delay(100);
  }
  Serial.println("BLE ready");
  Serial.print("Device Address = [");
  Serial.print(LBLE.getDeviceAddress());
  Serial.println("]");
  AService.addAttribute(ARead);
  LBLEPeripheral.addService(AService);
  LBLEPeripheral.begin();
  LBLEAdvertisementData advertisement;
  advertisement.configAsConnectableDevice("onoff");
  LBLEPeripheral.advertise(advertisement);
  LBLEPeripheral.setName("LED");
  AService.addAttribute(ARead);
}
 int test;
void loop() {
  Serial.print("conected=");
  Serial.println(LBLEPeripheral.connected());
  if (ARead.isWritten()) { 
      test = ARead.getValue(); 
    Serial.println(test);  
    if (test==48) {  
        digitalWrite(5, HIGH);
        Serial.println("LED off");
         Serial.println(test);
         delay(250);
    }else if(test==49){
        digitalWrite(5, LOW);
        Serial.println("LED on");
        Serial.println(test);
         delay(250);
          }else if(test=50){ 
        item=analogRead(A0);
       Serial.println(item);
       ARead.setValue(item); 
       delay(1000);
       ARead.setValue(test);  
          }      
    }               
}
