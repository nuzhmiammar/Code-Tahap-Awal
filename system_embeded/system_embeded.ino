#define BLYNK_PRINT Serial 
#include <Blynk.h>
#include <ESP8266WiFi.h>        
#include <BlynkSimpleEsp8266.h> 
#include <Wire.h>
#include <Adafruit_BME280.h> 
#include <Adafruit_Sensor.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
Adafruit_BME280 bme;
BlynkTimer timer;

char auth[ ] = "h3G4hGBqTvhcHaEWvGEyriRWl6JYVxA9"; // Kode unik
char ssid[ ] = "M5c new";    //Nama wifi
char pass[ ] = "cobaindlu";  //Pass wifi

void sendSensor(){
float h = bme.readHumidity();
float t = bme.readTemperature();
int lembab = analogRead(A0);
int value = map(lembab, 0, 1023, 0, 100);

  Blynk.virtualWrite(V1, h);
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V2, value);
}

BLYNK_WRITE(V1){
  int h = param.asInt();
  lcd.setCursor(6,0);
  lcd.print("H: ");
  lcd.print(h);
  lcd.print("");
}
BLYNK_WRITE(V0){
  int t = param.asInt();
  lcd.setCursor(0,0);
  lcd.print("T: ");
  lcd.print(t);
  lcd.print("");
}

void setup() {
  Serial.begin(9600);
  lcd.begin();
  bme.begin (0x76);
  Blynk.begin(auth, ssid, pass); 
  timer.setInterval(100L, sendSensor);
}


void loop(){
  Blynk.run();
  timer.run();
}
