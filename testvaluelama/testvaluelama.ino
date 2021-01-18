int newpo = 200 ;
int static oldpo = 200;
int steps;

void setup() {
  Serial.begin(9600);
}

void loop() {
 if (Serial.available()){
 newpo = Serial.parseInt();
 steps = newpo - oldpo;
 oldpo = newpo;

 Serial.println ("newpo:");
 Serial.println (newpo); 
 Serial.println ("oldpo:"); 
 Serial.println (oldpo); 
  Serial.println ("steps:"); 
 Serial.println (steps);
}
}

