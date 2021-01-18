#include <DS3231.h>

DS3231  rtc(SDA, SCL);

void setup(){
  Serial.begin(115200);
  // Uncomment the next line if you are using an Arduino Leonardo
  //while (!Serial) {}
  
  // Initialize the rtc object
  rtc.begin();
  
  // Setting waktu
 // rtc.setDOW(MONDAY);     // Set Day-of-Week to MONDAY
  rtc.setTime(12, 22, 40);     // Set the time to 12:00:00 (24hr format)
  rtc.setDate(24, 2, 2020);   // Set the date to January 1st, 2014
}

void loop()
{
  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // Send time
  Serial.println(rtc.getTimeStr());
  
  // Wait one second before repeating :)
  delay (1000);
}
