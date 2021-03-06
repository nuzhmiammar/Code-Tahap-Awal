#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //Interface pins of the LCD 
const int trig_pin=8;
const int echo_pin=7;
long distance,duration;

void setup() {
lcd.begin(16,2);
lcd.setCursor(0,0); //set the cursor to column 0 and line 0
pinMode(8,OUTPUT);
pinMode(9,INPUT);
}


void loop() {
digitalWrite(8,HIGH);
delayMicroseconds(20);
digitalWrite(8,LOW);
delayMicroseconds(20);
duration = pulseIn(echo_pin, HIGH); //To receive the reflected signal.
distance= duration*0.034/2;
lcd.setCursor(0,1); //set the cursor to column 0 and line 1
lcd.print(distance);
lcd.print("cm");
delay(100);
}
