//Digital 12 Hour Clock with DS1307
#include <Wire.h>
#include"RTClib.h"
#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
LiquidCrystal_I2C lcd(0x27,16,2);
RTC_DS1307 RTC;

int hr_24, hr_12;
int HOUR, MINUT, SECOND;

void setup()
{
  Wire.begin();
  RTC.begin();
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  lcd.setCursor(0, 0);
  lcd.print("REAL TIME CLOCK");
  lcd.setCursor(0, 1);
  lcd.print("MADE BY MUGDHO");
  delay(2000);
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
}
  void loop()
  {
    
    DateTime now = RTC.now();
    hr_24 = now.hour();
    if(hr_24==0)
    {
      hr_12 = 12;
    }
    else
    {
      hr_12 = hr_24%12;
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("TIME");
    lcd.setCursor(6, 0);
    lcd.print(HOUR = hr_12, DEC);
    lcd.print(":");
    lcd.print(MINUT = now.minute(), DEC);
    lcd.print(":");
    lcd.print(SECOND = now.second(), DEC);
    if(hr_24<12)
    {
      lcd.print("AM");
    }
    else{
      lcd.print("PM");
    }
    lcd.setCursor(0, 1);
    lcd.print("DATE:");
    lcd.print(now.day(), DEC);
    lcd.print("/");
    lcd.print(now.month(), DEC);
    lcd.print("/");
    lcd.print(now.year(), DEC);
   
    delay(1000);
  }

  
