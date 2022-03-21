#include "Ultrasonic.h"
#include <Servo.h>
int range;
Servo M1;
Ultrasonic __ultrasonic2(2);

void setup()
{
  Serial.begin(9600);
    M1.attach(10);
}


void loop()
{
  range = __ultrasonic2.MeasureInCentimeters();
  Serial.println(range);
  if (range < 10) {
      M1.write(90);
  delay(1000);
  } else {
       M1.write(180);
  delay(1000);
  }
}
