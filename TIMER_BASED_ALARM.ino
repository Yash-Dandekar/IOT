void setup() {
  // put your setup code here, to run once:
 pinMode(13,OUTPUT);
 pinMode(9,OUTPUT);   //pwm pin
}

void loop() {
  digitalWrite(13,HIGH);
  tone(9,1050,2000);

  digitalWrite(13,LOW);
  noTone(9);
  delay(2000);
}
