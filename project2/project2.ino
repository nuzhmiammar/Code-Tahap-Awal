#define trigPin 8
#define echoPin 7
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to
int count = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(trigPin, OUTPUT );
  pinMode(echoPin, INPUT  );
  pinMode(11, OUTPUT );
  pinMode(12, OUTPUT );
  Serial.begin(9600);
}
 void loop() {
  int buttonState = digitalRead(buttonPin);
    while (buttonState == LOW){
        count ++;   
      if (count != 5){
        switch(count){
          case 1:
            digitalWrite(13, HIGH);
            Serial.println("Maju");
            Serial.print("Gigi = ");
            Serial.println(count);
            delay(500);
            break;
          case 2:
            digitalWrite(13, HIGH);
            Serial.println("Maju");
            Serial.print("Gigi = ");
            Serial.println(count);
            delay(500);
            break;
          case 3:
            digitalWrite(13, HIGH);
            Serial.println("Maju");
            Serial.print("Gigi = ");
            Serial.println(count);
            delay(500);
            break;
          case 4:
            digitalWrite(13, HIGH);
            Serial.println("Maju");
            Serial.print("Gigi = ");
            Serial.println(count);
            delay(500);
            break;
          default:
      long duration, distance ;
      digitalWrite(trigPin, LOW);
      delay(2);
      digitalWrite(trigPin, HIGH);
      delay(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = (duration/2) /29.1;

       if (distance >=25){
          digitalWrite(12,LOW );
          digitalWrite(11,LOW );
          }
       if (distance <=15){
          digitalWrite(12,HIGH );
          digitalWrite(11,HIGH );
          delay(100);
          digitalWrite(12,LOW );
          digitalWrite(11,LOW );
          delay(100);
          }
            Serial.println("Mundur");
            delay(500);
        while (buttonState == LOW){
            count = 0;}
            break;
          }}}}
       
       
           
