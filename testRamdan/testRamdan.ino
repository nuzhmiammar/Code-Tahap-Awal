#include <SoftwareSerial.h>
#include <Servo.h>
#define m1 2
#define m2 3
#define m3 4
#define m4 5
#define servo1 9
#define servo2 10
Servo myservo1;
Servo myservo2;

int pos= 90;
int data=0,kec=0;
boolean maju=true;
int fast[11]={0,80,100,120,140,160,180,200,220,240,255};

void setup(){     
      pinMode(m1,OUTPUT);
      pinMode(m2,OUTPUT);
      pinMode(m3,OUTPUT);
      pinMode(m4,OUTPUT);
      Serial.begin(9600);
      myservo1.attach(servo1);
      myservo2.attach(servo2);
}

void motorOut(unsigned char lpwm, unsigned char rpwm, boolean arrow){
//arrow=false=maju; arrow=true=mundur;
if(arrow==false){
      digitalWrite(m3,HIGH);
      digitalWrite(m1,LOW);
      analogWrite(m4,255-lpwm);
      analogWrite(m2,rpwm);
      } else{
      digitalWrite(m3,LOW);
      digitalWrite(m1,HIGH);
      analogWrite(m4,lpwm);
      analogWrite(m2,255-rpwm);
      }
}

void loop(){
if(Serial.available()){
   data = Serial.read();}
   
  myservo1.write(90);
  myservo2.write(90);
  delay(500);
  myservo1.write(180);
  myservo2.write(0);
  delay(500);
  
if (data =='0') {kec = 0;}
if (data =='1') { kec = 1;}
if (data =='2') { kec = 2;}
if (data =='3') { kec = 3;}
if (data =='4') { kec = 4;}
if (data =='5') { kec = 5;}
if (data =='6') { kec = 6;}
if (data =='7') { kec = 7;}
if (data =='8') { kec = 8;}
if (data =='9') { kec = 9;}
if (data =='q') {kec = 10;}

            //S= Stop
if (data == 'S')
            { motorOut(0,0,false); }
            //F=Maju
if (data=='F')
            { motorOut(fast[kec],fast[kec],true); }
            //I=Maju sambil belok kanan
if (data=='I')
            { motorOut(fast[kec],((fast[kec])/2),true);}
            //G=Maju sambil belok kiri
if (data=='G')
            { motorOut(((fast[kec])/2),fast[kec],true); }
            //R=Belok kanan
if(data=='R')
            { motorOut(fast[kec],0,true); }
            //L=Belok kiri
if(data=='L')
            { motorOut(0,fast[kec],true); }
            //B=Mundur
if(data=='B')
            { motorOut(fast[kec],fast[kec],false); }
            //H=Mundur kiri
if (data=='H')
            { motorOut(((fast[kec])/2),fast[kec],false); }
            //Mundur kanan
if (data=='J')
            { motorOut(fast[kec],((fast[kec])/2),false); }     
      }
