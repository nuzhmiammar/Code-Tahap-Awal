int pbuttonPin = 2;
int relayPin = 10;

int val = 0;
int relayon = 0;
int tekan = 0;


void setup() {
  Serial.begin(9600);
  pinMode(pbuttonPin, INPUT_PULLUP); 
  pinMode(relayPin, OUTPUT);
 digitalWrite(relayPin, HIGH);
}

void loop() {
  val = digitalRead(pbuttonPin);

  if(val == HIGH && relayon == LOW){
    tekan = 1-tekan;
    delay(100);
  }    

  relayon = val;
      if(tekan == HIGH){
        Serial.println("Light ON");
        digitalWrite(relayPin, LOW); 
      }else{
        Serial.println("Light OFF");
        digitalWrite(relayPin, HIGH);   
      }     
delay(100);
}
