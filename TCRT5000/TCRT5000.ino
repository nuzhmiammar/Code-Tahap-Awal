#define tcrt A5

void setup() {
Serial.begin(9600);
}

void loop() {
int Hasilanalog = analogRead(tcrt);
float Volt = Hasilanalog*5.00/1024;
    Serial.print("Hasil Analog :");
    Serial.println(Hasilanalog);
    Serial.print("Nilai Volt :");
    Serial.println(Volt);
  delay(500);
  Serial.println(" ");
}
