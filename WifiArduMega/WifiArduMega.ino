#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <Adafruit_BME280.h> //libraries yang baru saja diinstall seperti cara diatas
#include <Adafruit_Sensor.h>  

#define EspSerial Serial2
#define ESP8266_BAUD 9600
ESP8266 wifi(&EspSerial);

#define SEALEVELPRESSURE_HPA (1013.25) //nilai awal untuk pressure
Adafruit_BME280 bme;
BlynkTimer timer;

char auth[ ] = "P1jSPgqLTzOavLOMYRmudxYDhZTDPTxZ"; // Kode unik
char ssid[ ] = "M5c new";    //Nama wifi
char pass[ ] = "cobaindlu";  //Pass wifi

WidgetLED ledmerah(V10);

void testinput(){
  ledmerah.on();
    Blynk.virtualWrite(V0, bme.readTemperature());
    Blynk.virtualWrite(V1, bme.readHumidity());
    Blynk.virtualWrite(V2, bme.readPressure() / 100.0F);
    Blynk.virtualWrite(V3, bme.readAltitude(SEALEVELPRESSURE_HPA));   
}

void setup(){
  Serial.begin(9600);
  bme.begin(0x76);
  EspSerial.begin(ESP8266_BAUD);
  timer.setInterval(500L, testinput);
   Blynk.begin(auth, wifi, ssid, pass);
}
 
void loop()
{
  Blynk.run();
  /* if (digitalRead(V9) == HIGH) {
   ledmerah.on();
}else{
   ledmerah.off();
}

    Blynk.virtualWrite(V0, bme.readTemperature());
    Blynk.virtualWrite(V1, bme.readHumidity());
    Blynk.virtualWrite(V2, bme.readPressure() / 100.0F);
    Blynk.virtualWrite(V3, bme.readAltitude(SEALEVELPRESSURE_HPA));
// */ timer.run();
}
