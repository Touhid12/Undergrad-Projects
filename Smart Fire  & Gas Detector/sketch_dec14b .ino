#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
#define lpg_sensor A4
#define buzzer 13
#define fan 6
const int sensor=A1;
float tempc;
float vout;
void setup()
{
  pinMode(lpg_sensor,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(sensor,INPUT);
  pinMode(fan,OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("LPG Gas and");
  lcd.setCursor(0,1);
  lcd.print("Temp. Detector");
  delay (2000);
}
void loop()
{
  vout=analogRead(sensor);
  vout=(vout*500)/1023;
  tempc=vout; 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp ('C)= ");
  lcd.print(tempc);
  delay(1000);

  if(digitalRead(lpg_sensor))
  {
    digitalWrite(buzzer,HIGH);
    //lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("LPG gas leakage");
    delay(400);
    digitalWrite(buzzer,LOW);
    delay(500);
    digitalWrite(buzzer,HIGH);
    delay(400);
    digitalWrite(buzzer,LOW);
    delay(500);
  }
  else
  {
    digitalWrite(buzzer,LOW);
    //lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("NO LPG lkage");
    delay(1000);
  }
     if(tempc>55)
  {
    digitalWrite(fan,HIGH);
    lcd.clear();
    lcd.print("Temperature High");
    lcd.setCursor(0,1);
    lcd.print("Fan Turning ON");
    delay(1000);
  }
  else
  {
    digitalWrite(fan,LOW);
    lcd.clear();
    lcd.print("Normal Temp");
    lcd.setCursor(0,1);
    lcd.print("Fan Turned OFF");
    delay(1000);
  }
}

