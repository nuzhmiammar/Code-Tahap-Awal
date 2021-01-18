#define BLYNK_PRINT Serial        
#include <ESP8266WiFi.h>        
#include <BlynkSimpleEsp8266.h>  
      
char auth[ ] = "5Dp15d_kiFYM-ru6PwFsaWA75bSvwgb-"; // Kode unik
char ssid[ ] = "M5c new";    //Nama wifi
char pass[ ] = "cobaindlu";  //Pass wifi

WidgetLED led1(V1);
int Reading = 0;

void setup()        
{ 
 digitalWrite(D0,HIGH); //Posisi awal Relay Mati       
 Serial.begin(9600);        
 Blynk.begin(auth, ssid, pass);        
}        
void loop()        
{        
 Blynk.run(); 
    int Reading = digitalRead(D0);
    if (Reading == 0){led1.on();}
        else {led1.off();}
}
