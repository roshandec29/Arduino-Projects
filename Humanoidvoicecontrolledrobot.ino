#include <SoftwareSerial.h>
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
SoftwareSerial BT(10, 11); //TX, RX respetively
String readvoice;
#define AM1 4       // left motor
#define AM2 5       // left motor
#define BM1 6       // right motor
#define BM2 7       // right motor
#define A1 12      // right motor hand
#define A2 2       // right motor hand
#define B1 3       // left motor hand
#define B2 8       // left motor
#define ledeye A0
#define ledteeth 13
int pos = 0;    // variable to store the servo positio
 
void setup() 
{
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
   pinMode(A0,OUTPUT);
 }
//---------------------------- ------------------------------ -------------//  
void loop() 
{
  while (BT.available())
  {               //Check if there is an available byte to read
  delay(10);      //Delay added to make thing stable 
  char c = BT.read();      //Conduct a serial read
  readvoice += c;           //build the string- "forward", "reverse", "left" and "right"
}  
  if (readvoice.length() > 0) 
  {
 Serial.println(readvoice); 
 if(readvoice == "blink")
 {
    digitalWrite(A0, HIGH);
    delay(2000);
    digitalWrite(A0, LOW);
  
 }
 else if(readvoice == "smile")
 {
   digitalWrite(13, HIGH);
   delay(2000);
   digitalWrite(13, LOW);
   }

 else if(readvoice == "hand")
 {
   digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(B1, HIGH);
  digitalWrite(B2, LOW);
  delay(500);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
  }
  else if(readvoice == "down")
  {
  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(B1, LOW);
  digitalWrite(B2, HIGH);
  delay(500);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
  }
else if(readvoice == "on") 
 {
  for (pos = 0; pos <= 180; pos += 5) 
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 5) 
  { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
 }
 else if(readvoice == "forward") 
  {
    digitalWrite(AM1, HIGH);
    digitalWrite(AM2, LOW);
    digitalWrite(BM1, HIGH);
    digitalWrite(BM2, LOW);
   digitalWrite(A1, LOW); // Hand Moment Right
  digitalWrite(A2, HIGH);
   delay(250);
  digitalWrite(A2,LOW);
   digitalWrite(A1,HIGH );
   delay(250);
   digitalWrite(B1,LOW); // Hand Moment Left
   digitalWrite(B2,HIGH);
   delay(250);
    digitalWrite(B2,LOW);
   digitalWrite(B1,HIGH);
  delay(250);           // Hand moment finish
   // Hand Moment Repeat
     digitalWrite(A1, LOW); // Hand Moment Right
  digitalWrite(A2, HIGH);
   delay(250);
  digitalWrite(A2,LOW);
   digitalWrite(A1,HIGH );
   delay(250);
   digitalWrite(B1,LOW); // Hand Moment Left
   digitalWrite(B2,HIGH);
   delay(250);
    digitalWrite(B2,LOW);
   digitalWrite(B1,HIGH);
  delay(250);           // Hand moment finish
   digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
  } 
  
  else if(readvoice == "backward") 
  {
    digitalWrite(AM1, LOW);
    digitalWrite(AM2, HIGH);
    digitalWrite(BM1, LOW);
    digitalWrite(BM2, HIGH);
   }
  
  else if (readvoice == "right")
  {
     digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    delay(500);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);   
    digitalWrite(AM1, HIGH);
    digitalWrite(AM2, LOW);
    digitalWrite(BM1,LOW );
    digitalWrite(BM2, HIGH);
    delay (8000);
   digitalWrite(AM1, LOW);
   digitalWrite(AM2, LOW);
   digitalWrite(BM1,LOW );
   digitalWrite(BM2, LOW);
   digitalWrite(A2, HIGH);
   digitalWrite(A1, LOW);
   delay(500);
   digitalWrite(A1, LOW);
   digitalWrite(A2, LOW);
  }
  
 else if ( readvoice == "left")
 {
     digitalWrite(B1, HIGH);
     digitalWrite(B2, LOW);
     delay(500);
     digitalWrite(B1, LOW);
     digitalWrite(B2, LOW);
     digitalWrite(AM1, LOW);
     digitalWrite(AM2, HIGH);
     digitalWrite(BM1, HIGH);
     digitalWrite(BM2, LOW);
     delay (8000);
     digitalWrite(AM1, LOW);
     digitalWrite(AM2,LOW);
     digitalWrite(BM1,LOW);
     digitalWrite(BM2,LOW);
     digitalWrite(B2, HIGH);
     digitalWrite(B1, LOW);
     delay(500);
    digitalWrite(B1, LOW);
    digitalWrite(B2, LOW);
 }
 
 else if (readvoice == "stop")
 {
   digitalWrite(AM1, HIGH);
   digitalWrite(AM2, HIGH);
   digitalWrite(BM1, HIGH);
   digitalWrite(BM2, HIGH);
   delay (100);
 }
 readvoice="";//Reset the variable
  }}
 
