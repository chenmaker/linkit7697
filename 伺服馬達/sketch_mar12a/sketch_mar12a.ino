#include <Servo.h>
Servo M1;
void setup() {
  M1.attach(10);
}

void loop() {
  M1.write(90);
  delay(1000);
  M1.write(180);
  delay(1000);
  M1.write(90);
  delay(1000);
  M1.write(0);
  delay(1000);
  M1.write(90);
  delay(1000);
  M1.write(180);
  delay(1000);
  M1.write(0);
  delay(1000);
  M1.write(180);
  delay(1000);
  M1.write(90);
  delay(1000);
}
