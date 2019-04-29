 #include <Servo.h>
 #define S0 2
 #define S1 3
 #define  S2 4
 #define S3 5
 #define sensorOut 6 
 Servo topServo;
 Servo bottomServo; 
 int frequency = 0;
 int color=0;
 
 void setup() {
 pinMode(S0, OUTPUT);
 pinMode(S1, OUTPUT);
 pinMode(S2, OUTPUT);
 pinMode(S3, OUTPUT);
 pinMode(sensorOut, INPUT);
 
 // Setting frequency-scaling to 20%
 digitalWrite(S0, HIGH);
 digitalWrite(S1, LOW);
 
 topServo.attach(7);
 bottomServo.attach(9);
 
 Serial.begin(9600);
 }
 
 void loop() {
 
 topServo.write(115);
 delay(100);
 
 for(int i = 115; i > 65; i--) {
 topServo.write(i);
 delay(100);
 Serial.println(" top servo");
 }
 delay(500);
 
 color = readColor();
 delay(10); 
 
 switch (color) {
 case 1:
 bottomServo.write(50);
 Serial.println(" bottom servo");
 break;
 
 case 2:
 bottomServo.write(75);
  Serial.println(" bottom servo");
 break;
 
 case 3:
 bottomServo.write(100);
  Serial.println(" bottom servo");
 break;
 
 case 4:
 bottomServo.write(125);
  Serial.println(" bottom servo");
 break;
 
 case 5:
 bottomServo.write(150);
  Serial.println(" bottom servo");
 break;
 
 case 6:
 bottomServo.write(175);
  Serial.println(" bottom servo");
 break;
 
 case 0:
 break;
 }
 delay(300);
 
 for(int i = 65; i > 29; i--) {
 topServo.write(i);
 delay(500);
  Serial.println(" top servo");
 } 
 delay(200);
 
 for(int i = 29; i < 115; i++) {
 topServo.write(i);
 delay(500);
 Serial.println(" top servo");
 }
 color=0;
 }
 
 // Custom Function - readColor()
 int readColor() {
 // Setting red filtered photodiodes to be read
 digitalWrite(S2, LOW);
 digitalWrite(S3, LOW);
 // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
   frequency = map(frequency, 25,72,255,0);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print(" ");
  delay(50);
  
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
   frequency = map(frequency, 30,90,255,0);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print(" ");
  delay(50);
  
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
   frequency = map(frequency, 25,70,255,0);
  
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println(" ");
  delay(50);
  
  if(R<45 & R>32 & G<65 & G>55){
  color = 1; // Red
  }
  if(G<55 & G>43 & B<47 &B>35){
  color = 2; // Orange
  }
  if(R<53 & R>40 & G<53 & G>40){
  color = 3; // Green
  }
  if(R<228 & R>217 & G<225 & G>216){
  color = 4; // Yellow
  }
  if(R<56 & R>46 & G<65 & G>55){
  color = 5; // Brown
  }
  if (G<58 & G>45 & B<40 &B>26){
  color = 6; // Blue
  }
  return color; 
 }
