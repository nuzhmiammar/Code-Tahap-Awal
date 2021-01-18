#include <Wire.h> 
#include <Adafruit_INA219.h> 
// Anda perlu mendownload library ini diatas dan copy paste sesuai perintah 
 
const int INA_addr = 0x41;  // INA219 address
 
Adafruit_INA219 ina219(INA_addr);
 
void setup(void) {
Serial.begin(9600); 
//prosedur mulai pembacaan data
ina219.begin();
} 
 
void loop(void) { 
 
float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;
  float power_mW = 0;

  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  power_mW = ina219.getPower_mW();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  
  Serial.print("Bus Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
  Serial.print("Shunt Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
  Serial.print("Load Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
  Serial.print("Current:       "); Serial.print(current_mA/2.5); Serial.println(" mA");
  Serial.print("Power:         "); Serial.print(power_mW); Serial.println(" mW");
  Serial.println("");

  delay(2000);
}
