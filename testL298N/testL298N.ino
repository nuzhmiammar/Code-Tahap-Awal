/* www.nyebarilmu.com */
 
//mendefinisikan pin yang digunakan untuk control pin
int IN_1 = 4;
int IN_2 = 5;

 
void setup()
{
  //mendefinisikan control pin sebagai output
 pinMode(IN_1, OUTPUT);
 pinMode(IN_2, OUTPUT);

}
 
void loop(){
 //Putar Mesin searah jarum jam
 digitalWrite(IN_1, HIGH);
 digitalWrite(IN_2, LOW);
 delay(3000);
 
 //Putar Motor a berlawan arah jarum jam
 digitalWrite(IN_1, LOW);
 digitalWrite(IN_2, HIGH);
 delay(3000);
} 
