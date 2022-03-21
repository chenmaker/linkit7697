#include "LTimer.h"
#include "Arduino.h"
LTimer timer0(LTIMER_0);
int bDo = 523;
int bRe = 587;
int bMi = 659;
int bFa = 698;
int bSo = 784;
int bLa = 880;
int bSi = 988;
int bDDo = 1047;
int duration = 500;
int i=14;
void _callback0(void *usr_data)
{
  analogRead(i);
  Serial.println(analogRead(i));
 /* if(i>2000){
    
    }else{
    tb();
    }*/
    tc();
}
void setup() 
{
  Serial.begin(9600);
  pinMode(i,INPUT);
  pinMode(3,OUTPUT);
  timer0.begin();
  timer0.start(500, LTIMER_REPEAT_MODE, _callback0, NULL);
}
void loop() 
{ 
}
