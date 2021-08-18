#include<LiquidCrystal.h>
LiquidCrystal lcd (12,11,5,4,3,2);

void setup() {
  lcd.begin(16,2);
  pinMode(10,INPUT);
  pinMode(9,INPUT);
  pinMode(8,INPUT);

}

void loop() {
  int x = digitalRead(10);
  int y = digitalRead(9);
  int z = digitalRead(8);

  if (x==1)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ITS NOT THE TIME TO");
    lcd.setCursor(0,1);
    lcd.print("LOOK FOR EXCUSES");
  }
if  (y==1)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" BE A WARRIOR,");
    lcd.setCursor(0,1);
    lcd.print("NOT A WORRIER");
  }
  if (z==1)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("DIE WITH MEMORIES");
    lcd.setCursor(0,1);
    lcd.print("NOT DREAMS....");
  }
  if(x==1 && y==1)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" WORRY LESS,");
    lcd.setCursor(0,1);
    lcd.print(" SMILE MORE.. ");
    
  }
  if(x==1 && z==1)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" BE A VOICE ");
    lcd.setCursor(0,1);
    lcd.print(" NOT AN ECHO");
    
  }
  if(y==1 && z==1)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("JUDGE ME WHEN");
    lcd.setCursor(0,1);
    lcd.print("YOU ARE PREFECT");
  }

  if(x==1 && y==1 &&z==1)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("MAKE IT HAPPEN");
    lcd.setCursor(0,1);
    lcd.print("SHOCK EVERYONE");
  }
 
  if(x==0 && z==0 && y ==0)
  {
    lcd.clear();
  }
   delay(2000);
}
