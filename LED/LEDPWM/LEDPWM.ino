void setup() {
  pinMode(15, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(13, OUTPUT);
}
 
void loop() {
   for(int i=13;i<=15;i++ ){        
     for(int p=0;p<=255;p++ ){  
      analogWrite(i,p ); 
      delay(50); 
    }
  }
}
