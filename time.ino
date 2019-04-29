#include<TimeLib.h>
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
//Serial.println(hour());            // the hour now  (0-23)
//time_t t = now();

  
}

void loop() {
  // put your main code here, to run repeatedly:
  time_t t = now();
 Serial.println(hour());
//  printDigits(minute());
 // printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.print(year()); 
 
  delay (1000);
}
