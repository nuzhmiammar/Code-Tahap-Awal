#include <DS3231.h>
 #include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

DS3231  rtc(SDA, SCL); //prosedur pembacaan I2C
Time t;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
rtc.begin();
  lcd.begin();
//rtc.setDate(6, 12, 2020);   //mensetting tanggal 07 april 2018
//rtc.setTime(20, 23, 40);     //menset jam 22:00:00
//rtc.setDOW(7);     //menset hari "selasa"
}

void loop() {
  // put your main code here, to run repeatedly:

Serial.print(rtc.getDOWStr());
Serial.print(",");
  
Serial.print(rtc.getDateStr());
Serial.print(",");
 
Serial.println(rtc.getTimeStr());
  t = rtc.getTime();
  lcd.setCursor(0,0);
  lcd.print(t.sec);
  lcd.print(" sec(s), ");
  
delay(1000);

}
