bool A = LOW;
bool B = LOW;

void setup() {
pinMode(2,INPUT);
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {

 A = digitalRead(2);
 if (A == HIGH && B == LOW)
 {
  digitalWrite(13,HIGH);
  Serial.print('y');
  delay(100);
  digitalWrite(13,LOW);
 }
 B = A;
  //  Serial.print('n');

}
