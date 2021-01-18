#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F_SEG 7
#define G 8
#define C1 9
#define C2 10
const int segs[7]={A,B,C,D,E,F_SEG,G};
const byte number[10]={0b1101111, 0b1111111, 0b0000111, 0b1111101, 0b1101101, 0b1100110, 0b1001111, 0b1011011, 0b0000110, 0b0111111};
void setup() {
pinMode(A, OUTPUT);
pinMode(B, OUTPUT);
pinMode(C, OUTPUT);
pinMode(D, OUTPUT);
pinMode(E, OUTPUT);
pinMode(F_SEG, OUTPUT);
pinMode(G, OUTPUT);
pinMode(C1,OUTPUT);
pinMode(C2, OUTPUT);
}
void loop() {
for (int digit1=0; digit1<10; digit1++){
for (int digit2=0; digit2<10; digit2++){
unsigned long startTime=millis();
for (unsigned long elapsed=0; elapsed<600; elapsed=millis()-startTime){
lightDigit1(number[digit1]);
delay(5);
lightDigit2(number[digit2]);
delay(5);
}
}
}
}
void lightDigit1(byte number){
digitalWrite(C1, LOW);
digitalWrite(C2, HIGH);
lightSegments(number);
}
void lightDigit2(byte number){
digitalWrite(C1, HIGH);
digitalWrite(C2, LOW);
lightSegments(number);
}
void lightSegments(byte number){
for (int i=0; i<7; i++){
int bit=bitRead(number, i);
digitalWrite(segs[i], bit);
}
}
