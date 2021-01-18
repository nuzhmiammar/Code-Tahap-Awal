byte speaker= 9;
void C1(){tone(speaker, 262);}
void C2(){tone(speaker, 294);}
void C3(){tone(speaker, 330);}
void C4(){tone(speaker, 349);}
void C5(){tone(speaker, 395);}
void C6(){tone(speaker, 440);}
void C7(){tone(speaker, 494);}
void C8(){tone(speaker, 523);}
void C0(){noTone(speaker);}
void D(){delay(200);}
void D1(){delay (1000);}
void setup(){
 pinMode(speaker,OUTPUT); 
}

void loop(){
C5(); D(); C5(); D(); C0(); D1();   C3();D();C8();D();C0(); D1();   C3();D();C2();D1();   C0(); D();C3();D();   C4();D();C6();D(); C5();D();C4();D();C3();D1();  C0(); D1(); C5();D();
}

// fungsi nada
