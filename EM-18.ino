
int count = 0;
//String c;
char c;
String id;
void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  Serial.println("Scan your card");
  

}

void loop() {
  // put your main code here, to run repeatedly:
 while(Serial.available());
 {
  //c=Serial.readString();
  c=Serial.read();
  count++;  //intially count=0
  id +=c;
  if(count==12)
  {
  Serial.println(id);
  if(id="012345KLIJ415 ")
  {
    Serial.println("Accepted");
    digitalWrite(13,HIGH);
  }
  else{
    Serial.println("Access Denied");
    digitalWrite(13,LOW);
  }
 }
  count=0; //so that new card it should come to zero
  id=" ";
}
}
