#include<KRwifi.h>
char* ssid = "M5c new";
char* pass = "cobaindlu"; 
 
void setup() {
  Serial.begin(9600);
  setWifi(ssid, pass);
}
 
void loop() {
 
}
