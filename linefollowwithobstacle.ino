int led1 = 11;
int led2 = 12;
int buzz = 8;
int ir1=10; // obstacle
int ir2=7;
int ir3=9;
int MA1=3;
int MA2=4;
int MB1=5;
int MB2=6;
void setup() {
  pinMode(7,INPUT);
  pinMode(9,INPUT);
   pinMode(10,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
   pinMode(8,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() 
{
 if (digitalRead(7)==HIGH && digitalRead(9)== HIGH)//MOTOR 1 FORWARD)
 {
  digitalWrite(11,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
 }
 
 if (digitalRead(7)==HIGH && digitalRead(9)== LOW)//MOTOR 1 FORWARD)
 {
  digitalWrite(11,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
 }
  if (digitalRead(7)==LOW && digitalRead(9)== HIGH)//MOTOR 1 FORWARD)
 {
  digitalWrite(11,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
 }
  if (digitalRead(7)==LOW && digitalRead(9)== LOW)//MOTOR 1 FORWARD)
 {
  digitalWrite(11,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
 }
  if (digitalRead(10)==HIGH)
  {
     digitalWrite(8,HIGH);
     delay(150);
      digitalWrite(8,LOW);
      delay(150);
       digitalWrite(8,HIGH);
     delay(150);
       digitalWrite(8,LOW);
    digitalWrite(12,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(11,LOW);
  digitalWrite(11,LOW);
  digitalWrite(11,LOW);
   digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  delay(5000);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  Serial.println("Reverse");
  delay(3000);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  Serial.println("Forward");
  if (digitalRead(7)==HIGH && digitalRead(9)== HIGH)//MOTOR 1 FORWARD)
 {
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
 }
 
 if (digitalRead(7)==HIGH && digitalRead(9)== LOW)//MOTOR 1 FORWARD)
 {
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
 }
  if (digitalRead(7)==LOW && digitalRead(9)== HIGH)//MOTOR 1 FORWARD)
 {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
 }
  if (digitalRead(7)==LOW && digitalRead(9)== LOW)//MOTOR 1 FORWARD)
 {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
 }
  
   }
 
 
  // put your main code here, to run repeatedly:
  }
