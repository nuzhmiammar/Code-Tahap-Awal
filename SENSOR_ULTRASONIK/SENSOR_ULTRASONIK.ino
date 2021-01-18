#define trigPin 7
#define echoPin 6


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trigPin, OUTPUT );
pinMode(echoPin, INPUT  );

pinMode(11, OUTPUT );
pinMode(12, OUTPUT );

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

  if (distance >=25)
{
  digitalWrite(12,LOW );
  digitalWrite(11,LOW );

}
if (distance <=15)
{
  digitalWrite(12,HIGH );
  digitalWrite(11,HIGH );
  delay(100);
  digitalWrite(12,LOW );
  digitalWrite(11,LOW );
  delay(100);
}
}
