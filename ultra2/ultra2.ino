#include <Ultrasonic.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

Ultrasonic mysensor;
float reading;

void setup() {
    lcd.init();                      // initialize the lcd 
    lcd.backlight();
    Serial.begin(9600);
    mysensor.attach(8,7);//Trigger pin , Echo pin
}

void loop() {
    reading=mysensor.distanceInCm();
     lcd.setCursor(0,0);
     lcd.print("Distance :- ");
      lcd.print(reading);

    delay(1000);
}
