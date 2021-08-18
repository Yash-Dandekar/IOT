#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);


byte man1[8]={
  0b001100,
  0b001110,
  0b001111,
  0b001110,
  0b000110,
  0b001001,
  0b010010,
  0b100010,
};
byte man2[8] ={
  0b00100,
  0b01110,
  0b01110,
  0b01100,
  0b00100,
  0b10010,
  0b10001,
  0b10001,
};

byte box[8]={
  0b00000,
  0b00000,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b00000,
  0b00000,
};

void setup() {
  
  lcd.begin(16,2);
  lcd.createChar(0,man1);
  lcd.createChar(1,man2);
  lcd.createChar(2,box);
  pinMode(9 , INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
      int i,val;
      val = digitalRead(9);
      
     for(int i=16 ; i>=0 ;i--)
  {
    lcd.setCursor(i,1);
    lcd.write(byte(2));
    delay(100);
    lcd.clear();
  
    if (val == 1) 
   {
   lcd.setCursor(4,0);
   lcd.write(byte(0));
   delay(200);
   

   lcd.setCursor(4,0);
   lcd.write(byte(1));
   }
  if (val==0)
   {
   lcd.setCursor(4,1);
   lcd.write(byte(0));
   delay(200);
   

   lcd.setCursor(4,1);
   lcd.write(byte(1));
   }
   
   
  


   
  }
}
