/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest
 
  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.
 
    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app
 
  Blynk library is licensed under MIT license
  This example code is in public domain.
 
 *************************************************************
 
  This example shows how to use ESP8266 Shield (with AT commands)
  to connect your project to Blynk.
 
  WARNING!
    It's very tricky to get it working. Please read this article:
    http://help.blynk.cc/hardware-and-libraries/arduino/esp8266-with-at-firmware
 
  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/
 
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <Wire.h>
 
char auth[ ] = "P1jSPgqLTzOavLOMYRmudxYDhZTDPTxZ"; // Kode unik
char ssid[ ] = "M5c new";    //Nama wifi
char pass[ ] = "cobaindlu";  //Pass wifi
 
// Hardware Serial on Mega, Leonardo, Micro...
#define EspSerial Serial2
 
// or Software Serial on Uno, Nano...
//#include <SoftwareSerial.h>
//SoftwareSerial EspSerial(2, 3); // RX, TX
 
// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600
 
ESP8266 wifi(&EspSerial);
 
void setup()
{
  // Debug console
  Serial.begin(9600);
 
  delay(10);
 
  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
 
  Blynk.begin(auth, ssid, pass);
}
 
void loop()
{
  Blynk.run();
}
