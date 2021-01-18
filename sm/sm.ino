#include <LiquidCrystal_I2C.h>
#include <I2CSoilMoistureSensor.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
 const int pinTanah = A5;
 float kelembapan;

void setup()
 {
  lcd.begin(16, 2);
  pinMode(pinTanah, INPUT);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pendeteksi");
  lcd.setCursor(0, 1);
  lcd.print("Kelembapan Tanah");
  delay(3000);
  lcd.clear();
  Serial.begin(9600);
 }

void loop()
 {
  int data = analogRead(pinTanah);
  kelembapan = (100 - (data * 0.0977));

//Menuliskan hasil persen kelembapan ke lcd
  lcd.setCursor(0, 0);
  lcd.print("Kelembapan= ");
  lcd.setCursor(13, 0);
  lcd.print(kelembapan);
  lcd.setCursor(15, 0);
  lcd.print("%");
    Serial.print("Kelembapan= ");
    Serial.print(kelembapan);
    Serial.println("%");
    Serial.println(kelembapan);
 }
