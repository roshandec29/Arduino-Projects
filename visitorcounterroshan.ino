#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define ir 10
#define led 13
int count=0;
void IR()
{
    count++;
    Serial.println("Person In Room");
    Serial.println(count);
    delay(500);
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
    count--;
    Serial.println("Person In Room");
    Serial.println(count);
    delay(500);
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
}
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Visitor Counter");
  delay(2000);
  pinMode(ir, INPUT);
  pinMode(led, OUTPUT);
  lcd.clear();
  lcd.print("Person In Room:");
  lcd.setCursor(0,1);
  lcd.print(count);
}
void loop()
{  
  
  if(digitalRead(ir))
  IR();
  
  if(count<=0)
  {
    Serial.println("Novbody In Room");
    delay(500);
    lcd.clear();
    digitalWrite(led, LOW);
    lcd.clear();
    lcd.print("Nobody In Room");
    lcd.setCursor(0,1);
    lcd.print("Light Is Off");
    delay(200);
  }
  
  else
    digitalWrite(led, HIGH);
  
}

