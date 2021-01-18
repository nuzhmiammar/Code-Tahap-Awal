#define BLYNK_PRINT Serial        
#include <ESP8266WiFi.h>        
#include <BlynkSimpleEsp8266.h>  
      
char auth[ ] = "9OuLxEUt6JUkwRsQJ3Dp77Kzt7Zs1mEd";
char ssid[ ] = "M5c new";
char pass[ ] = "cobaindlu";  
     
void setup()        
{        
 Serial.begin(9600);        
 Blynk.begin(auth, ssid, pass);        
}        
void loop()        
{        
 Blynk.run();        
}     
