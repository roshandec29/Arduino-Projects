
#include <Servo.h>

Servo myservo;  // create servo object to control a servo// Dustbin
// twelve servo objects can be created on most boards

Servo myservo1; // Placer

int pos1 = 0;    // variable to store the servo position
int pos2 = 0;  
void setup() 
{
myservo.attach(8);  // attaches the servo on pin 9 to the servo object
myservo1.attach(9); 
}
void loop() 
{
  for (pos1 = 0; pos1 <= 70; pos1 += 10) { // goes from 0 degrees to 180 degrees
      //in steps of 1 degree
    myservo.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(150);                       // waits 15ms for the servo to reach the position
  }
  for (pos2 = 0; pos2 <= 240; pos2 += 10) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  }
   for (pos1 = 70; pos1 >= 35; pos1 -= 10) { // goes from 180 degrees to 0 degrees
    myservo.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(150); 
   }   
  
  for (pos2= 180; pos2 >= 0; pos2 -= 10) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  }
}
