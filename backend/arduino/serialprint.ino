bool SW1 = LOW;
bool SW2 = LOW;
bool SW3 = LOW;
bool SW4 = LOW;
bool SW5 = LOW;
bool SW6 = LOW;
bool SW7 = LOW;
bool SW8 = LOW;
bool SW9 = LOW;
bool SW10 = LOW;
bool SW11 = LOW;
bool prevstate1 = LOW;
bool prevstate2 = LOW;
bool prevstate3 = LOW;
bool prevstate4 = LOW;
bool prevstate5 = LOW;
bool prevstate6 = LOW;
bool prevstate7 = LOW;
bool prevstate8 = LOW;
bool prevstate9 = LOW;
bool prevstate10 = LOW;
bool prevstate11 = LOW;

void setup() {
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
pinMode(8,INPUT);
pinMode(9,INPUT);
pinMode(10,INPUT);
pinMode(11,INPUT);
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void leerflanco(bool SW, bool prevstate,String output){
   if (SW == HIGH && prevstate == LOW)
 {
  digitalWrite(13,HIGH);
  Serial.print(output);
  delay(200);
  digitalWrite(13,LOW);
 }
}

void loop() {

 SW1 = digitalRead(2);
 SW2 = digitalRead(3);
 SW3 = digitalRead(4);
 SW4 = digitalRead(5);
 SW5 = digitalRead(6);
 SW6 = digitalRead(7);
 SW7 = digitalRead(8);
 SW8 = digitalRead(9);
 SW9 = digitalRead(10);
 SW10 = digitalRead(11);

 leerflanco(SW1,prevstate1,"a");
 leerflanco(SW2,prevstate2,"b");
 leerflanco(SW3,prevstate3,"c");
 leerflanco(SW4,prevstate4,"d");
 leerflanco(SW5,prevstate5,"e");
 leerflanco(SW6,prevstate6,"f");
 leerflanco(SW7,prevstate7,"g");
 leerflanco(SW8,prevstate8,"h");
 leerflanco(SW9,prevstate9,"i");
 leerflanco(SW10,prevstate10,"j");




 prevstate2 = SW2;
 prevstate1 = SW1;
 prevstate3 = SW3;
 prevstate4 = SW4;
 prevstate5 = SW5;
 prevstate6 = SW6;
 prevstate7 = SW7;
 prevstate8 = SW8;
 prevstate9 = SW9;
 prevstate10 = SW10;
 prevstate11 = SW11;


}
