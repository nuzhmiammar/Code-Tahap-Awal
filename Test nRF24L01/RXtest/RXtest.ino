#include <SPI.h>  
#include "nRF24L01.h"
#include "RF24.h" 

RF24 myRadio (9, 10); 
struct package
{
  int id=0;
  float temperature = 0.0;
  char  text[100] ="";
};

byte addresses = '0xE8E8F0F0E1LL'; 



typedef struct package Package;
Package data;

void setup() 
{
  Serial.begin(115200);
  delay(1000);

  myRadio.begin(); 
 // myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
//  myRadio.setDataRate( RF24_250KBPS ) ; 
  myRadio.openReadingPipe(1, addresses);
  myRadio.startListening();
}


void loop()  
{

while (myRadio.available())
    {
      myRadio.read( &data, sizeof(data) );
    }
    Serial.print("\nPackage:");
    Serial.print(data.id);
    Serial.print("\n");
    Serial.println(data.temperature);
    Serial.println(data.text);
  }
