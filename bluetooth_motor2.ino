#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,8,7,4,2);
#define m1 4
#define m2 5
#define m3 6
#define m4 7
const int t=11;
const int e=10;
long dur;
int dis;
String rk;
void setup() {
  Serial.begin(9600);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
   pinMode(t,OUTPUT);
   pinMode(e,INPUT);
    lcd.begin(16,2);
}

void loop() {
   digitalWrite(t,LOW);
  delayMicroseconds(2);
   digitalWrite(t,HIGH);
    delayMicroseconds(10);
     digitalWrite(t,LOW);
     dur=pulseIn(e,HIGH);
     dis=dur*0.034/2;
  while(Serial.available())
  {
    delay(3);
    char g=Serial.read();
    rk+=g;
  }
  if(rk.length()>0)
  {
    if(rk=="forward")
    { 
      if(dis>=8)
      {
      digitalWrite(m1,HIGH);
       digitalWrite(m2,LOW);
      digitalWrite(m3,HIGH);
       digitalWrite(m4,LOW);
       Serial.print("readString ==");
       Serial.println(rk);
       lcd.setCursor(0,0);
  lcd.print("MOVES FORWARD");
      }
    }
       if(rk=="reverse")
    {
       if(dis>=8)
      {
      digitalWrite(m2,HIGH);
       digitalWrite(m1,LOW);
      digitalWrite(m4,HIGH);
       digitalWrite(m3,LOW);
       Serial.print("readString ==");
       Serial.println(rk);
              lcd.setCursor(0,0);
  lcd.print("MOVES BACKWARD");
      }
    }
       if(rk=="left")
    {
        if(dis>=8)
      {
      digitalWrite(m2,HIGH);
       digitalWrite(m1,LOW);
      digitalWrite(m3,HIGH);
       digitalWrite(m4,LOW);
       Serial.print("readString ==");
       Serial.println(rk);
              lcd.setCursor(0,0);
  lcd.print("MOVES LEFT        ");
    }
    }
       if(rk=="right")
    {
        if(dis>=8)
      {
      digitalWrite(m1,HIGH);
       digitalWrite(m2,LOW);
      digitalWrite(m4,HIGH);
       digitalWrite(m3,LOW);
       Serial.print("readString ==");
       Serial.println(rk);
              lcd.setCursor(0,0);
  lcd.print("MOVES RIGHT      ");
    }
    }
       if(rk=="stop")
    {
      digitalWrite(m1,LOW);
       digitalWrite(m2,LOW);
      digitalWrite(m3,LOW);
       digitalWrite(m4,LOW);
       Serial.print("readString ==");
       Serial.println(rk);
              lcd.setCursor(0,0);
  lcd.print("STOPS             ");
    }
    rk="";
  }
    if(dis<8)
      {
      digitalWrite(m1,LOW);
       digitalWrite(m2,LOW);
      digitalWrite(m3,LOW);
       digitalWrite(m4,LOW);  
       delay(500);
       lcd.setCursor(0,0);
  lcd.print("SYSTEM STOPS   ");
    digitalWrite(m1,LOW);
       digitalWrite(m2,HIGH);
      digitalWrite(m3,LOW);
       digitalWrite(m4,HIGH);  
       delay(1000);
          digitalWrite(m1,LOW);
       digitalWrite(m2,LOW);
      digitalWrite(m3,LOW);
       digitalWrite(m4,LOW); 
     }
}
