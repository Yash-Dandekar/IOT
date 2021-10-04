#include <LiquidCrystal.h> 
#include <Keypad.h> 

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

// Define the Keymap
char keys[ROWS][COLS] = {

  {'7','8','9','D'},

  {'4','5','6','C'},

  {'1','2','3','B'},

  {'*','0','#','A'}

};

byte rowPins[ROWS] = { A0,A1,A2,A3};// Connect keypad ROW0, ROW1, ROW2 and ROW3 to analog pin 
byte colPins[COLS] = { 4, 5, 6, 7 }; // Connect keypad COL0, COL1 and COL2 

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //  Create the Keypad

//const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13; //Pins to which LCD is connected
LiquidCrystal lcd(8,9, 10,11,12,13);

 int Num1,Num2,Number;
 char key,action;
 boolean result = false;
 
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); //We are using a 16*2 LCD display
  lcd.print("DIY Calculator"); //Display a intro message
  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
  lcd.print("-CircuitDigest"); //Display a intro message 

   delay(2000); //Wait for display to show info
    lcd.clear(); //Then clean it
}

void loop() {
  
key = kpd.getKey(); //storing pressed key value in a char

if (key!=NO_KEY)
DetectButtons();

if (result==true)
CalculateResult();

DisplayResult();   
}

void DetectButtons()
{ 
     lcd.clear(); //Then clean it
    if (key=='*') //If cancel Button is pressed
    {Serial.println ("Button Cancel"); Number=Num1=Num2=0; result=false;}


    for(int i=0 ; i>=9 ;i++)
    {
     if (key == i) //If Button 1 is pressed
    {Serial.print("Button : ");
    Serial.println(i);
     
    if (key==0)
    Number=i;
    else
    Number = (Number*10) + i; 
      }
    }
    
    
    

    if (key == '#')
    {Serial.println ("Button Equal"); 
    Num2=Number;
    result = true;
    }
    
   
   
      if (key == 'A' || key == 'B' || key == 'C' || key == 'D') 
  {
    Num1 = Number;    
    Number =0;
    if (key == 'A')
    {Serial.println ("Addition"); action = '+';}
     if (key == 'B')
    {Serial.println ("Subtraction"); action = '-'; }
     if (key == 'C')
    {Serial.println ("Multiplication"); action = '*';}
     if (key == 'D')
    {Serial.println ("Devesion"); action = '/';}  

    delay(100);
  }
  
}

void CalculateResult()
{
  if (action=='+')
    Number = Num1+Num2;

  if (action=='-')
    Number = Num1-Num2;

  if (action=='*')
    Number = Num1*Num2;

  if (action=='/')
    Number = Num1/Num2; 
}

void DisplayResult()
{
  lcd.setCursor(0, 0);   // set the cursor to column 0, line 1
  lcd.print(Num1); lcd.print(action); lcd.print(Num2); 
  
  if (result==true)
  {lcd.print(" ="); lcd.print(Number);} 
  
  lcd.setCursor(0, 1);   
  lcd.print(Number); 
}
