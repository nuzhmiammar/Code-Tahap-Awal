
#define xAxis A1     // A0 for Arduino UNO
#define yAxis A0     // A1 for Arduino UNO

int buttonUp    = 2;
int buttonRight = 3;
int buttonDown  = 5;
int buttonLeft  = 4;


void setup() {
  Serial.begin(9600);
  pinMode(buttonUp,INPUT_PULLUP);
  pinMode(buttonRight,INPUT_PULLUP);
  pinMode(buttonDown,INPUT_PULLUP);
  pinMode(buttonLeft,INPUT_PULLUP);
}

void loop() {
      Serial.print("X = ");
      Serial.print(analogRead(xAxis));
      Serial.print(" Y = ");  
      Serial.print(analogRead(yAxis));
      Serial.print(" Atas = "); 
      Serial.print(digitalRead(buttonUp));
      Serial.print(" Kanan = "); 
      Serial.print(digitalRead(buttonRight));
      Serial.print(" Bawah = "); 
      Serial.print(digitalRead(buttonDown));
      Serial.print(" Kiri = "); 
      Serial.println(digitalRead(buttonLeft));
}
