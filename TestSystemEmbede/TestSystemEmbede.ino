#define BLYNK_PRINT Serial 
#include <Blynk.h>
#include <ESP8266WiFi.h>        
#include <BlynkSimpleEsp8266.h> 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h> 

        
LiquidCrystal_I2C lcd(0x27,16,2);
Adafruit_BME280 bme;
BlynkTimer timer;

char auth[ ] = "h3G4hGBqTvhcHaEWvGEyriRWl6JYVxA9";
char ssid[ ] = "M5c new";
char pass[ ] = "cobaindlu";

void sendSensor(){
      int val = analogRead(A0); //pembacaan kelembaban
      int A = map(val,0,1023,100,0);
      float K = bme.readHumidity();
      float S = bme.readTemperature();   
    Blynk.virtualWrite(V2, A);
    Blynk.virtualWrite(V1, K);
    Blynk.virtualWrite(V0, S);
}

void setup() {
  Serial.begin(9600);
  lcd.begin();
  bme.begin (0x76);
  pinMode(D4,OUTPUT);
  Blynk.begin(auth, ssid, pass); 
      lcd.setCursor(0, 0);
      lcd.print("SMART GREENHOUSE");
      lcd.setCursor(0, 1);
      lcd.print("Tanah :");
      lcd.setCursor(11, 1);
      lcd.print("%");
 // timer.setInterval(1000L, sendSensor);
}

void loop() {
  Blynk.run();
      int val = analogRead(A0); //pembacaan kelembaban
      int A = map(val,0,1023,100,0);
      float K = bme.readHumidity();
      float S = bme.readTemperature();
      lcd.setCursor(7, 1);  
      lcd.print(A);
    Blynk.virtualWrite(V2, A);
    Blynk.virtualWrite(V1, K);
    Blynk.virtualWrite(V0, S);
}
