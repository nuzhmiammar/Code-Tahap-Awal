#include <LiquidCrystal_I2C.h>
#define trigPin 8
#define echoPin 7
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
const int  buttonPin = 2;
int count = 1;
float distance;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(trigPin, OUTPUT );
  pinMode(echoPin, INPUT  );
  pinMode(11, OUTPUT );
  pinMode(12, OUTPUT );
  lcd.begin(16,2);
  }

 void loop() {
  int buttonState = digitalRead(buttonPin);
         long duration, distance ;
         digitalWrite(trigPin, LOW);
         delay(2);
         digitalWrite(trigPin, HIGH);
         delay(10);
         digitalWrite(trigPin, LOW);
         duration = pulseIn(echoPin, HIGH);
         distance = (duration/2) /29.1;
         
    if (buttonState == LOW){
        count ++;
        delay(200);}
           
    if (count != 5){
       digitalWrite(13, HIGH);
       lcd.setCursor(0,0);
       lcd.print("                ");
       lcd.setCursor(0,1);
       lcd.print("                ");
       lcd.setCursor(0,0);
       lcd.print("Kendaraan Maju");
       lcd.setCursor(0,1);
       lcd.print("Gigi = ");
       lcd.print(count);
       }
       
    if (count == 5){      
            if (distance >=41){
                digitalWrite(12,LOW );
                digitalWrite(11,LOW );
                }
            if (distance <=40){
                digitalWrite(12,HIGH );
                digitalWrite(11,HIGH );
                delay(150);
                digitalWrite(12,LOW );
                digitalWrite(11,LOW );
                delay(150);
                }
            if (distance <=15){
                digitalWrite(12,HIGH );
                digitalWrite(11,HIGH );
                delay(50);
                digitalWrite(12,LOW );
                digitalWrite(11,LOW );
                delay(50);
                }
                       lcd.setCursor(0,0);
                       lcd.print("                ");
                       lcd.setCursor(0,1);
                       lcd.print("                ");
                       lcd.setCursor(0,0);
                       lcd.print("Jarak Mundur:");
                       lcd.setCursor(0,1);
                       lcd.print(distance);
                       lcd.print(" cm");
                       delay(100);
                        }
    if (count == 6){
      count = 1;
      }}
