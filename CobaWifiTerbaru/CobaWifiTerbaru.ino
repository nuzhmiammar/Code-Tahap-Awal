#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <Blynk.h>

#include <SoftwareSerial.h>
#define ESP8266_BAUD 9600

char auth[] = "nrplP-BAzz4BgeyDniwRkS4qDuapI4BX";
char ssid[ ] = "M5c new";    //Nama wifi
char pass[ ] = "cobaindlu";  //Pass wifi

#define EspSerial Serial2 // RX, TX
WidgetLCD lcd(V0);

ESP8266 wifi(&EspSerial);

void setup(){
  Serial.begin(9600);
  EspSerial.begin(ESP8266_BAUD);
Blynk.begin(auth, wifi, ssid, pass);
Blynk.begin(auth, wifi, ssid, pass, "blynk-cloud.com", 8080);
   lcd.clear();
 lcd.print(1, 1, "IoT");
}

void loop()
{
  Blynk.run();
}
