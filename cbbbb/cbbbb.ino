#define trigPin 9
#define echoPin 8
void setup() {
  pinMode(trigPin, OUTPUT );
  pinMode(echoPin, INPUT  );
  Serial.begin(9600);
}

void loop() {
         long duration, distance ;
         digitalWrite(trigPin, LOW);
         delay(2);
         digitalWrite(trigPin, HIGH);
         delay(10);
         digitalWrite(trigPin, LOW);
         duration = pulseIn(echoPin, HIGH);
         distance = (duration/2) /29.1;
Serial.println(distance);
  delay(500);
}
