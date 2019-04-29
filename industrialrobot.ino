#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

Servo myservo1;

int pos = 0;    // variable to store the servo position 
int ir1=7;
int ir2=9;
int MA1=3;
int MA2=4;
int MB1=5;
int MB2=6;
int buzz=10;
void setup() {
  pinMode(7,INPUT);
  pinMode(9,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
   myservo.attach(8);
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() 
{
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
  delay(3000);
  Serial.println("Dust Collected Started");
  delay(500);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  Serial.println("Forward");
  delay(1000);
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
  Serial.println("Placing Started");
  digitalWrite(buzz,HIGH);
  delay(100);
  digitalWrite(buzz,HIGH);
  delay(100);
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(25);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(25);                       // waits 15ms for the servo to reach the position
  }
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  Serial.println("Forward");
  delay(500);
 }}
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
  
