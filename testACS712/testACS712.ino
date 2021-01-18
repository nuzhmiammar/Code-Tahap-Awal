/*
Measuring Current Using ACS712
*/
int mVperAmp = 77; // use 185 for 5A, 100 for 20A Module and 66 for 30A Module
int ACSoffset = 2500; 

void setup(){ 
 Serial.begin(9600);
}

void loop(){
  
int RawValue = analogRead(A1);
 float Voltage = (RawValue * 5.0)/1024; // Gets you mV
 float Amps = ((Voltage - ACSoffset) / mVperAmp);
 float trms = 0+0.0752*RawValue;
 
 
 Serial.print("Raw Value = " ); // shows pre-scaled value 
 Serial.print(RawValue); 
 Serial.print("\t mV = "); // shows the voltage measured 
 Serial.print(Voltage,1); // the '3' after voltage allows you to display 3 digits after decimal point
 Serial.print("\t Amps = "); // shows the voltage measured 
 Serial.println(trms,3); // the '3' after voltage allows you to display 3 digits after decimal point
 delay(1000); 
 
}
