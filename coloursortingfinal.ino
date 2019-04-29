/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo topservo;  // create servo object to control a servo
Servo bottomservo;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int pos1= 0;
int buzz = 10;
void setup() {
  topservo.attach(8);  // attaches the servo on pin 9 to the servo object
  bottomservo.attach(9);
  pinMode(buzz,OUTPUT);
}

void loop() {
   
    for (pos = 160; pos >= 129; pos -= 1) { // goes from 180 degrees to 0 degrees
    topservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  delay(2000);
    //for (pos1 = 30; pos <= 150; pos += 1) { // goes from 180 degrees to 0 degrees
    bottomservo.write(120);              // tell servo to go to position in variable 'pos'
    //delay(30);                       // waits 15ms for the servo to reach the position
  //}
  for (pos = 129; pos >= 80; pos -= 1) { // goes from 180 degrees to 0 degrees
    topservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 80; pos <= 160; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    topservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  digitalWrite(buzz,HIGH);
  delay(500);
  digitalWrite(buzz,HIGH);
  delay(500);
   digitalWrite(buzz,LOW);
  delay(500);
  digitalWrite(buzz,LOW);
  delay(500);
  delay(5000);
    for (pos = 160; pos >= 129; pos -= 1) { // goes from 180 degrees to 0 degrees
    topservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  delay(2000);
    //for (pos1 = 30; pos <= 150; pos += 1) { // goes from 180 degrees to 0 degrees
    bottomservo.write(160);              // tell servo to go to position in variable 'pos'
    //delay(30);                       // waits 15ms for the servo to reach the position
  //}
  for (pos = 129; pos >= 80; pos -= 1) { // goes from 180 degrees to 0 degrees
    topservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 80; pos <= 160; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    topservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  digitalWrite(buzz,HIGH);
  delay(500);
  digitalWrite(buzz,HIGH);
  delay(500);
   digitalWrite(buzz,LOW);
  delay(500);
  digitalWrite(buzz,LOW);
  delay(500);
  delay(5000);
      for (pos = 160; pos >= 129; pos -= 1) { // goes from 180 degrees to 0 degrees
    topservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  delay(2000);
    //for (pos1 = 30; pos <= 150; pos += 1) { // goes from 180 degrees to 0 degrees
    bottomservo.write(80);              // tell servo to go to position in variable 'pos'
    //delay(30);                       // waits 15ms for the servo to reach the position
  //}
  for (pos = 129; pos >= 80; pos -= 1) { // goes from 180 degrees to 0 degrees
    topservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 80; pos <= 160; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    topservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  digitalWrite(buzz,HIGH);
  delay(500);
  digitalWrite(buzz,HIGH);
  delay(500);
   digitalWrite(buzz,LOW);
  delay(500);
  digitalWrite(buzz,LOW);
  delay(500);
  delay(5000);
}

//   for (pos = 100; pos >= 40; pos -= 1) { // goes from 180 degrees to 0 degrees
//    topservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = 40; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    topservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);     
//   }
//   delay(2000);
//   for (pos = 180; pos >= 100; pos -= 1) { // goes from 180 degrees to 0 degrees
//    topservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15); // waits 15ms for the servo to reach the position
//  }
//    delay(2000);
//     for (pos1 = 0; pos1 <= 180; pos1 += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    bottomservo.write(pos1);              // tell servo to go to position in variable 'pos'
//    delay(15);     
//   
//  }
//   for (pos = 100; pos >= 40; pos -= 1) { // goes from 180 degrees to 0 degrees
//    topservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = 40; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    topservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);     
//   }
//  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }


