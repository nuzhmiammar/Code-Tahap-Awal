#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);
void setup(){
lcd.begin(16,2);
lcd.setBacklight(HIGH);
}
void loop(){
lcd.setCursor(5,0);
lcd.print("YOSSI");
lcd.setCursor(0,1);
lcd.print("REAL ENGINEER");
}
