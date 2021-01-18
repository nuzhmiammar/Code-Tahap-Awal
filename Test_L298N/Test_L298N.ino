#include<Servo.h>
#define enA 5 //PWM
#define enB 6 //PWM
#define in1 2
#define in2 4
#define in3 7
#define in4 8
#define servo1 9  // first servo //PWM
#define servo2 10  // second servo //PWM
#define joyH A3    // L/R Parallax Thumbstick
#define joyV A2    // U/D Parallax Thumbstick  
int motorSpeedA = 0;
int motorSpeedB = 0;                                
int servoVal;          // variable to read the value from the analog pin
int servoVal2;
Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin (9600) ;
  myservo1.attach(servo1);  // attaches the servo
  myservo2.attach(servo2);  // attaches the servo
}

void loop() {
  int xAxis = analogRead(A0); // Read Joysticks X-axis
  int yAxis = analogRead(A1); // Read Joysticks Y-axis 
   
servoVal = analogRead(joyH);         
servoVal = map(servoVal, 1023, 0, 0, 180);     // scale it to use it with the servo (result  between 0 and 180)
myservo2.write(servoVal);                         // sets the servo position according to the scaled value
delay(15);   

servoVal = analogRead(joyV);          
servoVal2 = map(servoVal, 0, 1023, 0, 180);     // scale it to use it with the servo (result between 70 and 180)
myservo1.write(servoVal2);                           // sets the servo position according to the scaled value
delay(15);  
  
if (yAxis < 470) {
    // Convert the declining X-axis readings from 470 to 0 into increasing 0 to 255 value
    int yMapped = map(yAxis, 470, 0, 0, 255);
    // Move to left - decrease left motor speed, increase right motor speed
    motorSpeedA = motorSpeedA - yMapped;
    motorSpeedB = motorSpeedB + yMapped;
    // Confine the range from 0 to 255
    if (motorSpeedA < 0) {
      motorSpeedA = 0;
    }
    if (motorSpeedB > 255) {
      motorSpeedB = 255;
    }}
    
if (yAxis > 550) {
    // Convert the increasing X-axis readings from 550 to 1023 into 0 to 255 value
    int yMapped = map(yAxis, 550, 1023, 0, 255);
    // Move right - decrease right motor speed, increase left motor speed
    motorSpeedA = motorSpeedA + yMapped;
    motorSpeedB = motorSpeedB - yMapped;
    // Confine the range from 0 to 255
    if (motorSpeedA > 255) {
      motorSpeedA = 255;
    }
    if (motorSpeedB < 0) {
      motorSpeedB = 0;
    }}

       // Y-axis used for forward and backward control
if (xAxis < 470) {
    // Set Motor A backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B backward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    // Convert the declining Y-axis readings for going backward from 470 to 0 into 0 to 255 value for the PWM signal for increasing the motor speed
    motorSpeedA = map(xAxis, 470, 0, 0, 255);
    motorSpeedB = map(xAxis, 470, 0, 0, 255);
    }
  
if (xAxis > 550) {
    // Set Motor A forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Set Motor B forward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    // Convert the increasing Y-axis readings for going forward from 550 to 1023 into 0 to 255 value for the PWM signal for increasing the motor speed
    motorSpeedA = map(xAxis, 550, 1023, 0, 255);
    motorSpeedB = map(xAxis, 550, 1023, 0, 255);
    }
  
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
  motorSpeedA = 0;
  motorSpeedB = 0;
                     
                                     // waits for the servo to get there
}
