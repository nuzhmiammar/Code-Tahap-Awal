#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define wash 7
#define dry 6

void setup(){
  lcd.begin();
    pinMode(wash,INPUT_PULLUP);
    pinMode(dry,INPUT_PULLUP);
  lcd.setCursor(1,0);
  lcd.print("Automatic Wash");
  lcd.setCursor(1,1);
  lcd.print("Drying  System");
  delay(2000);
  lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Loading");
      delay(1000);
    lcd.setCursor(8,0);
    lcd.print(".");
    delay(1000);
      lcd.setCursor(10,0);
      lcd.print(".");
      delay(1000);
       lcd.setCursor(12,0);
       lcd.print(".");
       delay(1000);
        lcd.setCursor(14,0);
        lcd.print(".");
        delay(1000);
       lcd.clear();
}

void loop(){
int HC = digitalRead(wash); // HC = Hasil Cuci
int HP = digitalRead(dry);  // HP = Hasil Pengering

if (HP == 0){
      lcd.setCursor(0,0);
      lcd.print(" Chamber Proces ");
  lcd.setCursor(0,1);
  lcd.print("  Drying  Time  ");
    delay(20);
}else if (HC == 0){
      lcd.setCursor(0,0);
      lcd.print(" Chamber Proces ");
  lcd.setCursor(0,1);
  lcd.print("  Washing Time  ");
    delay(20);
}else{
  lcd.setCursor(0,0);
  lcd.print(" Automatic Wash ");
  lcd.setCursor(0,1);
  lcd.print(" Drying  System ");;
}
}
