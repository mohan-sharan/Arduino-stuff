#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

int REDLED = 28;
int YELLOWLED = 32;
int BLUELED = 36;

char incoming_data = '\0';

void setup() 
{
   Serial.begin(9600);

   lcd.begin(16, 2);
   lcd.setCursor(0, 0);
   lcd.print("GUESS!");

   lcd.createChar(1, smiley);
   lcd.createChar(2, frownie);
   
   pinMode(REDLED, OUTPUT);
   pinMode(YELLOWLED, OUTPUT);
   pinMode(BLUELED, OUTPUT);

}

void loop() 
{
  if (Serial.available() > 0)
  {
    incoming_data = Serial.read();

    if (incoming_data == 'r')
    {
      //RED LED - ON
      digitalWrite(REDLED, HIGH);

      digitalWrite(YELLOWLED, LOW);
      digitalWrite(BLUELED, LOW);

      lcd.setCursor(0, 0);
      lcd.print("GAME OVER! ");
      lcd.write((byte)2);
      
      delay(3000);

      //LCD - CLEAR
      lcd.clear();

    }
    else if (incoming_data == 'b')
    {
      //BLUE LED - ON
      digitalWrite(BLUELED, HIGH);
      
      digitalWrite(REDLED, LOW);
      digitalWrite(YELLOWLED, LOW);

      lcd.setCursor(0, 0);
      lcd.print("YOU WIN ");
      lcd.write((byte)1);

      delay(3000);

      //LCD - CLEAR
      lcd.clear();
      
    }
    else if (incoming_data == 'g')
    {
      //YELLOW LED - ON
      digitalWrite(YELLOWLED, HIGH);
      
      digitalWrite(BLUELED, LOW);   
      digitalWrite(REDLED, LOW);

      lcd.setCursor(0, 0);
      lcd.print("GUESS!");

    } 
    else if (incoming_data == 'l')
    {
      lcd.setCursor(0, 1);
      lcd.print("LITTLE LOWER..");

      delay(1000);

      //LCD - CLEAR
      lcd.clear();      
    }
    else if (incoming_data == 'h')
    {
      lcd.setCursor(0, 1);
      lcd.print("LITTLE HIGHER...");

      delay(1000);

      //LCD - CLEAR
      lcd.clear();      
    } 
     
    else if (incoming_data == 'x')
    {
      //LEDs - OFF
      digitalWrite(YELLOWLED, LOW);      
      digitalWrite(BLUELED, LOW);   
      digitalWrite(REDLED, LOW); 
      //LCD - CLEAR
      lcd.clear();
    } 
  }                 
}
