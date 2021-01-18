#include<Servo.h>
Servo servo1;
Servo servo2;
int a_key = A0; //joystik Control Servo Atas                                               
int b_key = A1; //joystick Control Servo Bawah                                              
int a_pos;
int b_pos;
int servo1_pin = 8;  //Atas Servo tangan
int servo2_pin = 9;  //Bawah Servo tangan
int initial_position = 90;
int initial_position1 = 90;

void setup ( ) {
Serial.begin (9600) ;
servo1.attach (servo1_pin ) ; 
servo2.attach (servo2_pin ) ; 
servo1.write (initial_position);
servo2.write (initial_position1);
pinMode (a_key, INPUT) ;                     
pinMode (b_key, INPUT) ;                      
}

void loop ( ) {
a_pos = analogRead (a_key) ;  
b_pos = analogRead (b_key) ;                      

if (a_pos < 300){
if (initial_position < 10) {
    }else{
    initial_position = initial_position - 20;
    servo1.write ( initial_position ) ;
    delay (100) ; }}
     
if (a_pos > 700){
if (initial_position > 180){  
    }else{
    initial_position = initial_position + 20;
    servo1.write ( initial_position ) ;
    delay (100) ;
    }}

if (b_pos < 300){
if (initial_position1 < 10) {
    }else{
    initial_position1 = initial_position1 - 20;
    servo2.write ( initial_position1 ) ;
    delay (100) ; 
    }} 
    
if (b_pos > 700){
if (initial_position1 > 180){  
    }else{
    initial_position1 = initial_position1 + 20;
    servo2.write ( initial_position1 ) ;
    delay (100) ;
    }}
}
