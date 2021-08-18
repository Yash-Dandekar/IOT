#include<Servo.h>
Servo myservo;

void setup() {
 Serial.begin(9600);

 myservo.attach(9);
 pinMode(13,OUTPUT);

}

void loop() {
   if(Serial.available());
  {
    String val = Serial.readString();
    Serial.print(val);
    
    if(val=="open")
    {     
    for (int pos = 0; pos <= 90; pos += 1) {
   
      myservo.write(pos);  
      digitalWrite(13,HIGH);            
      delay(15);                       
     }  
    }
    if(val=="close")
    {
      for (int pos = 90 ; pos >= 0; pos -= 1) {
   
      myservo.write(pos);  
      digitalWrite(13,LOW);            
      delay(15); 
      }
    }
   }
}
