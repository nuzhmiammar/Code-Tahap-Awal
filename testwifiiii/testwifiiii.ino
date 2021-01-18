#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

char auth[] = "pIQlV71Dtkw7fzZKUhWkyzvOainks9zI";
char ssid[ ] = "M5c new";    //Nama wifi
char pass[ ] = "cobaindlu";  //Pass wifi

#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX
#define ESP8266_BAUD 9600
BlynkTimer timer;
#include <Servo.h>
Servo servo1;

int trig_pin = 8;
int echo_pin = 9;
long echotime; 
float distance;

ESP8266 wifi(&EspSerial);

void sensor (){
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  echotime= pulseIn(echo_pin, HIGH);
  distance= 0.0001*((float)echotime*340.0)/2.0;
int y = map(distance, 1, 30, 0, 90);
  Serial.print(distance);

 servo1.write(y);
}

 void setup()
 {
   // Debug console
  // Set ESP8266 baud rate
  EspSerial.begin(9600);
  delay(10);

   // Blynk will work through Serial
   Serial.begin(9600);
   Blynk.begin(auth, wifi, ssid, pass, "blynk-cloud.com", 8080);
  timer.setInterval(100L, sensor);
  servo1.attach(7);
  pinMode(trig_pin, OUTPUT); 
  pinMode(echo_pin, INPUT);
  digitalWrite(trig_pin, LOW);  
 }
 
BLYNK_CONNECTED(){
  Blynk.syncAll();  
}

 void loop(){
   Blynk.run();
     timer.run();
 }
