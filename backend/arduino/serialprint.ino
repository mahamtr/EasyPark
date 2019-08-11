bool SW1 = LOW;
bool SW2 = LOW;

bool prevstate1 = LOW;
bool prevstate2 = LOW;



void setup() {
pinMode(2,INPUT);
pinMode(3,INPUT);

pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {

 SW1 = digitalRead(2);
 SW2 = digitalRead(3);

    
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

 prevstate2 = SW2;
 prevstate1 = SW1;
 

}
