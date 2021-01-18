
#define BLYNK_PRINT Serial
//#include <ESP8266_Lib.h>
//#include <BlynkSimpleShieldEsp8266.h>
#include "ESP8266WiFi.h"
//#include <BlynkSimpleEsp8266.h>
//#include <SimpleTimer.h>
//#include <SoftwareSerial.h>
#define ESP8266_BAUD 9600

char auth[] = "NEdrr88T2Iz8wgU7ulrpAm6E7815Ptvs";
char ssid[] = "M5c new"; //You can replace the wifi name to your wifi 
char pass[] = "cobaindlu";  //Type password of your wifi.

#define EspSerial Serial2 // RX, TX
WidgetLCD lcd(V13);

//ESP8266 wifi(&EspSerial);

void setup()
{

  Serial.begin(115200);
  EspSerial.begin(ESP8266_BAUD);
    Blynk.begin(auth, ssid, pass);
 // Blynk.begin(auth, wifi, ssid, pass);
// Blynk.begin(auth, ssid, pass, "192.168.43.234", 80);
   lcd.clear();
 lcd.print(1, 1, "IoT");
}

void loop()
{
  Blynk.run();
}
