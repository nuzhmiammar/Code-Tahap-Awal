#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_BME280.h> //libraries yang baru saja diinstall seperti cara diatas
#include <Adafruit_Sensor.h>  

LiquidCrystal_I2C lcd(0x27,16,2);
 
#define SEALEVELPRESSURE_HPA (1013.25) //nilai awal untuk pressure
Adafruit_BME280 bme; //penggunaan I2C
 
void setup(){
  Serial.begin(9600);
  lcd.begin();
 
  lcd.setCursor(00,00);
  lcd.print(" nyebarilmu.com ");
  lcd.setCursor(00,1);
  lcd.print(" Modul BME280");
  delay(2000);
  lcd.clear();
 
  if (!bme.begin(0x76)) {
    lcd.setCursor(00,00);
    lcd.print("no sensor BME280");
    lcd.setCursor(00,1);
    lcd.print("Cek rangkaian");
    while (1);
  }
  lcd.clear();
  delay(1000);
  lcd.clear();
}
 
void loop(){
lcd.setCursor(00,00);
lcd.print("T:"); 
lcd.print(bme.readTemperature());
lcd.print((char)223);
lcd.println("C"); 
 
//pembacaan data Kelembaban
lcd.setCursor(9,00);
lcd.print("H:"); 
lcd.print(bme.readHumidity()); 
lcd.print("%"); 
 
//pembacaan data tekanan atmosfer 
lcd.setCursor(00,1);
lcd.print("P:");
lcd.print(bme.readPressure() / 100.0F);
lcd.println("hPa");
 
//pembacaan data ketinggian berdasarkan permukaan laut
lcd.setCursor(9,1);
lcd.print("A:");
lcd.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
lcd.println("m");
 
delay(1000);
}
