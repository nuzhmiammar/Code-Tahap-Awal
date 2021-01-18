#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {

pinMode(9,OUTPUT); 
digitalWrite(9,HIGH);
Serial.begin(9600);
Serial.println("Enter AT commands:");
mySerial.begin(38400);
}

void loop()
{
if (mySerial.available())
  Serial.write(mySerial.read());

if (Serial.available())
  mySerial.write(Serial.read());
}
