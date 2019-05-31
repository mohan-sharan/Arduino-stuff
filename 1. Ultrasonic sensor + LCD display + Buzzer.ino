#include <LiquidCrystal.h>

const int trig_pin = 9;
const int echo_pin = 10;
const int buzzer_pin = 8;

int distance_cm;
long duration;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(buzzer_pin, OUTPUT);
}

void loop() 
{   
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);

  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  duration = pulseIn(echo_pin, HIGH);
  distance_cm = (duration*0.034)/2.0;

  if (distance_cm >= 10 || distance_cm <= 0)
  {
  digitalWrite(buzzer_pin, LOW);  
  lcd.setCursor(0, 0);
  lcd.print("NO OBJECT[>10cm]"); 
  lcd.setCursor(0, 1);
  lcd.print("DETECTED!");
  delay(1000);
  lcd.clear();
  }
  else
  {
  digitalWrite(buzzer_pin, HIGH);  
  lcd.setCursor(0, 0);
  lcd.print("DISTANCE(cm):"); 
  lcd.print(distance_cm);
  lcd.setCursor(0, 1);
  lcd.print("OBJECT DETECTED!"); 
  delay(1000);
  lcd.clear();
  }
}
