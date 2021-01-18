#include <Wire.h>              // include Arduino wire library (required for I2C devices)
#include <Adafruit_GFX.h>      // include Adafruit graphics library
#include <Adafruit_SSD1306.h>  // include Adafruit SSD1306 OLED display driver
#include <Adafruit_BME280.h>   // include Adafruit BME280 sensor library
#include <DS3231.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 
// define device I2C address: 0x76 or 0x77 (0x77 is library default address)
#define BME280_I2C_ADDRESS  0x76
Adafruit_BME280  bme280;  // initialize Adafruit BME280 library

DS3231  rtc(SDA, SCL);
char _buffer[31];
 
void setup(){
    rtc.begin(); 
          display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
          display.clearDisplay();
          display.setTextSize(1);   // text size = 1
          //display.invertDisplay(true);
          //display.setTextColor(BLACK,WHITE);  // set text color to white and black background
          display.setTextColor(WHITE,BLACK);
          display.display();        // update the display
 
    //    initialize the BME280 sensor
  if( bme280.begin(BME280_I2C_ADDRESS) == 0 ){  
    //    connection error or device address wrong!
          display.setCursor(34, 23);
          display.print("Connection");
          display.setCursor(49, 33);
          display.print("Error");
          display.display();        // update the display
          while(1);                 // stay here
  }
 
//  blok();
  display.setCursor(0, 10);
  display.print("TEMPERATURE:");
  display.setCursor(0, 20);
  display.print("HUMIDITY:");
  display.setCursor(0, 30);
  display.print("PRESSURE:");
  display.setCursor(0, 50);
  display.print("X:");
  display.setCursor(64, 50);
  display.print("Y:"); 
}

  void loop(){  
   ///*
  display.setCursor(0, 40);  
  display.print(rtc.getDateStr());
  display.print("-");
  display.println(rtc.getTimeStr());
  
  
   float temp = bme280.readTemperature();    // get temperature in degree Celsius
  float humi = bme280.readHumidity();       // get humidity in rH%
  float pres = bme280.readPressure();       // get pressure in Pa

  // print all data on the display
  // 1: print temperature
  if(temp < 0)
    sprintf(_buffer, "-%02u.%02u C", (int)abs(temp), (int)(abs(temp) * 100) % 100 );
  else
    sprintf(_buffer, " %02u.%02u C", (int)temp, (int)(temp * 100) % 100 );
    
  display.setCursor(70, 10);
  display.println(_buffer);
  // print degree symbols ( ° )
  display.drawRect(107, 10, 3, 3, WHITE);

    
  // 2: print humidity
  sprintf(_buffer, "%02u.%02u %%", (int)humi, (int)(humi * 100) % 100 );
  display.setCursor(55, 20);
  display.print(_buffer);
    
  // 3: print pressure
  sprintf(_buffer, "%04u.%02u hPa", (int)(pres/100), (int)((uint32_t)pres % 100) );
  display.setCursor(55, 30);
  display.print(_buffer);
 
  delay(1000);  // wait a second
 // display.display();
 // */  
 /*
float x = analogRead(A1);
float y = analogRead(A0);

    sprintf(_buffer, "%04u", (int)x );
    display.setCursor(0, 50);
    display.print(_buffer);
    sprintf(_buffer, "%04u", (int)y);
    display.setCursor(65, 50);
    display.print(_buffer);
  display.display();
  delay(10);
  */
}

/*void blok(){
    display.setCursor(50, 0);  
  display.print(rtc.getDOWStr());
  display.display();
  display.startscrollright(0x00,0x00);

  display.display();        // update the display
}*/


