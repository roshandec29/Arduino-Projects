#define RELAY1  6  
String bt;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(RELAY1, OUTPUT);     
}

void loop() {
  // put your main code here, to run repeatedly:
while (  Serial.available()  )
{
  delay(3);
  char c = Serial.read();
bt +=c;
}

if (bt.length()>0 )
{
  Serial.println(bt);
  if (bt == "ON")
  {
    digitalWrite(RELAY1,1);          // Turns Relay ON
   Serial.println("Light ON");
   Serial.print("readString ==");
  Serial.println(bt);
  }
  if (bt == "OFF")
  {
     digitalWrite(RELAY1,0);          // Turns Relay Off
   Serial.println("Light OFF");
   Serial.print("readString ==");
  Serial.println(bt);
   }
  bt="";
}}
