

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[][6] = {"00001","00002"};
const int pinout = 7;
const int pinin = 4; //input from button to arduino

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openWritingPipe(address[1]);
  radio.setPALevel(RF24_PA_MIN); // it doesn't matter what power level we use (MIN, LOW, HIGH, MAX)it still works for my trial
  radio.stopListening();
  
  pinMode(pinin, INPUT);
  pinMode(pinout, OUTPUT);
}
void loop() {
  digitalWrite(pinout, HIGH);
  
  int tombol = digitalRead(pinin);
  
  if(tombol != LOW){
  txin();}
  else{
  Serial.println("Press the button to send data");
  delay(1000);}
}
void txin(){
  bool txan;
  const char data[] = "Hello World";
  txan = radio.write(&data, sizeof(data));
  delay(1000);
  if(txan)
    Serial.println("Data Sent");
  else
    Serial.println("Failed");
}
