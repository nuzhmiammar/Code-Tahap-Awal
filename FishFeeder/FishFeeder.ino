#include <Servo.h>
#include <DS3231.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo servo1;
DS3231  rtc(SDA, SCL); //prosedur pembacaan I2C
Time t;

void setup() {
Serial.begin(9600);
rtc.begin();
lcd.begin();
 servo1.attach(6); 
   servo1.write(92);
}

void loop() {
    t = rtc.getTime();
lcd.setCursor(0,0);
  lcd.print(rtc.getDOWStr(1));
  lcd.print(",");
  lcd.print(rtc.getDateStr());
  lcd.print(",");
  lcd.setCursor(0,1);
  lcd.print(rtc.getTimeStr());
  
  if(t.hour == 13 && t.min == 02  && t.sec == 01){
      servo1.write(89);
      delay(6000);
      servo1.write(92);
    }
    
}
