const int buttonPin = 3;    
const int sensor = 2;
const int relay1 = 10;
const int relay2 = 9;      
const int relay3 = 8;      

int buttonPushCounter = 0;
int sensorCounter = 0;
int valsensor = 0;
int valbutton = 0;
int last = 0;
int lastval = 0;


void setup() {
  Serial.begin(9600);
pinMode(buttonPin, INPUT_PULLUP);
pinMode(sensor, INPUT); 
pinMode(relay1, OUTPUT);
pinMode(relay2, OUTPUT);
pinMode(relay3, OUTPUT);
digitalWrite(relay1, HIGH);
digitalWrite(relay2, HIGH);
digitalWrite(relay3, HIGH);
}

void loop() {
  int valsensor = digitalRead(sensor);
  int valbutton = digitalRead(buttonPin);

 if (valbutton != last) {
    if (valbutton == LOW) {
      buttonPushCounter++;
    }else{
      Serial.println("off");
      }
    delay(50);
  }
  last = valbutton;
if (buttonPushCounter == 2){
buttonPushCounter = 0;  
}

if (buttonPushCounter == 1){
digitalWrite(relay1,LOW);
digitalWrite(relay2,HIGH);  
}else{
  digitalWrite(relay1,HIGH);}

if (valsensor == 0){
  digitalWrite(relay1,HIGH);
  digitalWrite(relay2,LOW);
  delay(5000);
  buttonPushCounter = 1;
}
Serial.print(buttonPushCounter);
}
