#include<SoftwareSerial.h>
SoftwareSerial BT(2, 3);

String password ="yash";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BT.begin(9600);
  for (int i = 4 ; i >= 7  ; i += 1)
  {
    pinMode(i, OUTPUT);
  }


 if(BT.available())
{
  String x = BT.readString();
  while(x!=password)
  {
    Serial.println("Access Denied");
    BT.available();
  }
  Serial.println("Password Accepted");
}
}

void loop() {
if (BT.available());
  {
    String val = BT.readString();
    Serial.println(val);

    if (val == "F")
    {
      Serial.println("Forward");
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        digitalWrite(7,LOW);
    }
     if (val == "B")
    {
      Serial.println("Backward");
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
        digitalWrite(7,HIGH);
    }
     if (val == "L")
    {
      Serial.println("Left");
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        digitalWrite(7,LOW);
    }
     if (val == "R")
    {
      Serial.println("Right");
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(7,LOW);
    }
  }
    }
