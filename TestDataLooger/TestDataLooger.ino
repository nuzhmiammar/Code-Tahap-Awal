#include <Wire.h>
#include <Adafruit_INA219.h> 
#include <DS3231.h> //memasukan library DS3231
#include <SPI.h> 
#include <SD.h>
#include <Adafruit_BME280.h> //libraries yang baru saja diinstall seperti cara diatas
#include <Adafruit_Sensor.h> 
#include <BH1750.h>
 
DS3231  rtc(SDA, SCL); //prosedur pembacaan I2C
File myFile;
const int INA_addr = 0x41;
Adafruit_INA219 ina219(INA_addr);
BH1750 lightMeter(0x23);
#define SEALEVELPRESSURE_HPA (1013.25) //nilai awal untuk pressure
Adafruit_BME280 bme;
 
void setup()
{
//set komunikasi baut di serial monitor pada kecepatan 9600
Serial.begin(9600);
//menuliskan data di serial monitor
Serial.println("Trial Data Logger Arduino");
Serial.println("nyebarilmu.com");
delay(3000); //Waktu jeda
 
//prosedur pembacaan RTC DS3231
rtc.begin();
 ina219.begin();
 bme.begin(0x76);
    lightMeter.begin();
   lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE);
  //setting pertama download program
 // rtc.setDate(21, 5, 2020);   //mensetting tanggal 07 april 2018
  //rtc.setTime(21, 19, 30);     //menset jam 22:00:00
 // rtc.setDOW(5);     //menset hari "selasa"
 
 Serial.println("Read MicoSd Card");
 delay(1000);
 
 if (!SD.begin(4)) 
 {
 Serial.println("Failed read microsd card on module!");
 return;
 }
 Serial.println("Success read microsd card");
 delay(1000);
} 
 
void loop()
{
   float busvoltage = 0;
    float current_mA = 0;
      busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
 myFile = SD.open("DAY1PV.txt", FILE_WRITE); //Membuka File datalogger.txt
 if (myFile) // jika file tersedia tulis data
 {
Serial.print(rtc.getDOWStr(1));
Serial.print(",");
myFile.print(rtc.getDOWStr(1));
myFile.print(",");
  
Serial.print(rtc.getDateStr());
Serial.print(",");
myFile.print(rtc.getDateStr());
myFile.print(",");
 
Serial.print(rtc.getTimeStr());
Serial.print(",");
myFile.print(rtc.getTimeStr());
myFile.print(",");

Serial.print(busvoltage);
Serial.print(",");
myFile.print(busvoltage);
myFile.print(",");
  
Serial.print(current_mA/2.5);
Serial.print(",");
myFile.print(current_mA/2.5);
myFile.print(",");
 
Serial.print(bme.readTemperature());
Serial.print(",");
myFile.print(bme.readTemperature());
myFile.print(",");

Serial.println(lightMeter.readLightLevel());
myFile.println(lightMeter.readLightLevel());
myFile.close();
 }
 else 
 {
 Serial.println("Failed open datalogger.txt"); // jika gagal print error
 }
 delay(60000); //total jeda yaitu 5 detik karena proses penulisan data kurang lebih 3 detik
}
