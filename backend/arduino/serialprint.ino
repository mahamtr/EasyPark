bool SW1 = LOW;
bool SW2 = LOW;
bool SW3 = LOW;
bool SW4 = LOW;
bool SW5 = LOW;
bool prevstate1 = LOW;
bool prevstate2 = LOW;
bool prevstate3 = LOW;
bool prevstate4 = LOW;
bool prevstate5 = LOW;


void setup() {
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {

 SW1 = digitalRead(2);
 SW2 = digitalRead(3);
 SW3 = digitalRead(4);
 SW4 = digitalRead(5);
 SW5 = digitalRead(6);
    
 if (SW1 == HIGH && prevstate1 == LOW)
 {
  digitalWrite(13,HIGH);
  Serial.print('i');
  delay(200);
  digitalWrite(13,LOW);
 }
 if (SW2 == HIGH && prevstate2 == LOW)
 {
  digitalWrite(13,HIGH);
  Serial.print('o');
  delay(200);
  digitalWrite(13,LOW);
 }
  if (SW3 == HIGH && prevstate3 == LOW)
 {
  digitalWrite(13,HIGH);
  Serial.print('o');
  delay(200);
  digitalWrite(13,LOW);
 }
  if (SW4 == HIGH && prevstate4 == LOW)
 {
  digitalWrite(13,HIGH);
  Serial.print('o');
  delay(200);
  digitalWrite(13,LOW);
 }
  if (SW5 == HIGH && prevstate5 == LOW)
 {
  digitalWrite(13,HIGH);
  Serial.print('o');
  delay(200);
  digitalWrite(13,LOW);
 }
 prevstate2 = SW2;
 prevstate1 = SW1;
  prevstate3 = SW3;
   prevstate4 = SW4;
    prevstate5 = SW5;
 

}
