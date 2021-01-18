#define BLYNK_PRINT Serial 

#include <Blynk.h>
#include <ESP8266WiFi.h>        
#include <BlynkSimpleEsp8266.h> 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2);    // set the LCD I2C address

char auth[ ] = "h3G4hGBqTvhcHaEWvGEyriRWl6JYVxA9"; // Kode unik
char ssid[ ] = "M5c new";    //Nama wifi
char pass[ ] = "cobaindlu";  //Pass wifi

WidgetLED ledmerah(V10);
WidgetLED ledkuning(V11);
WidgetLED ledhijau(V12);

#define BLYNK_GREEN     "#33CC33"
#define BLYNK_BLUE      "#0033CC"
#define BLYNK_YELLOW    "#FFFF00"
#define BLYNK_RED       "#FF0000"
#define BLYNK_BLACK     "#000000"

String gaugeColor;

byte slot1[8]   = {B00000, B01010, B01010, B01010, B01010, B01101, B01000, B01000};
byte slot2[8]   = {B11100, B00100, B01000, B00100, B11100, B00000, B00000, B00000};

void setup() {
  Serial.begin(115200);
  lcd.begin();
  //Serial.begin(9600);
  Blynk.begin(auth, ssid, pass); 
  lcd.createChar(1, slot1);
  lcd.createChar(2, slot2);
}

void micro(int x){ 
    lcd.setCursor(x,1);
    lcd.write(1);
  }
void tiga(int y){ 
    lcd.setCursor(y,1);
    lcd.write(2);
  }
  
void loop() {
  Blynk.run();
      int ppm = analogRead(A0); //pembacaan kelembaban
      int gaugeValue = analogRead(A0);

    Blynk.virtualWrite(V0, ppm);
    Blynk.virtualWrite(V1, gaugeValue);
      lcd.setCursor(1, 0);
      lcd.print("KUALITAS UDARA");
      lcd.setCursor(0, 1);
      lcd.print("PPM:");
      lcd.setCursor(4, 1);
      lcd.print(ppm);
      lcd.print(" ");
      micro (8);
      lcd.setCursor(9, 1);
      lcd.print("gram/m");
      tiga (15);      
      
  String newColor;
  if (gaugeValue > 420)      {newColor = BLYNK_BLACK;} 
  else if (gaugeValue > 350) {newColor = BLYNK_RED;} 
  else if (gaugeValue > 150) {newColor = BLYNK_YELLOW;}
  else if (gaugeValue > 50)  {newColor = BLYNK_BLUE;} 
  else                       {newColor = BLYNK_GREEN;}

  if (newColor != gaugeColor) {
    gaugeColor = newColor;
    Blynk.setProperty(V1, "color", gaugeColor);}
    
  if (gaugeValue > 350)       { ledmerah.on();
                                ledkuning.off();
                                ledhijau.off();}
  else if (gaugeValue > 75 )  { ledmerah.off();
                                ledkuning.on();
                                ledhijau.off();}
  else                        { ledmerah.off();
                                ledkuning.off();
                                ledhijau.on();}
}
