#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h>
int buzzer=8;

RTC_DS1307 RTC;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup () {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
  Wire.begin();
  RTC.begin();

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop () {
    DateTime now = RTC.now();

      lcd.setCursor(0,0);
    lcd.print("TIME: ");
    lcd.print(now.hour(), DEC);
    lcd.print(":");
    lcd.print(now.minute(), DEC);
    lcd.print(":");
    lcd.print(now.second(), DEC); 
    
    lcd.setCursor(0,1);
    lcd.print("DATE: ");
    lcd.print(now.year(), DEC);
    lcd.print("/");
    lcd.print(now.month(), DEC);
    lcd.print("/");
    lcd.print(now.day(), DEC);

    delay(1000);    
    if(now.second()>40&now.second()<50){
      tone(buzzer,200);
      }
    else{
      noTone(buzzer);
      }
}
