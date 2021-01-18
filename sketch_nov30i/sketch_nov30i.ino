//Project 6 - Light Sensor
int ledPin = 5; // Pin we will connect to LED
int ldrPin = A0; // Pin connected to LDR
int lightVal = 0; // Value read from LDR
void setup() {
// Set both pins as outputs
pinMode(ledPin, OUTPUT);
pinMode(ldrPin, INPUT);
}
void loop() {
// Read in value from LDR
lightVal = analogRead(ldrPin);
// Turn LED on
digitalWrite(ledPin, HIGH);
// Delay of length lightVal
delay(lightVal);
// Turn LED off
digitalWrite(ledPin, LOW);
// Delay again
delay(lightVal);
}
