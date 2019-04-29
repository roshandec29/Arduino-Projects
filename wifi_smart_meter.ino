#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

#include <NTPtimeESP.h>
#define DEBUG_ON
NTPtime NTPch("in.pool.ntp.org");
strDateTime dateTime;

int led_pin =D6;
int int0_pin=D3;
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
const char *ssid =  "RK";     
const char *pass =  "roshan123";
const char * apiKey = "AECYZQAVWPOBMH68";
const char* server1= "api.thingspeak.com";
unsigned long channel = 525842;
// OLED display TWI address
#define OLED_ADDR   0x3C
WiFiServer server(80);
WiFiClient client;
Adafruit_SSD1306 display(-1);
int count=0;
volatile int pulse_seen = 0;
void setup() {
   pinMode(led_pin, OUTPUT);
   pinMode(D7, OUTPUT);
 Serial.begin(9600);
  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();
  digitalWrite(D7, HIGH);
   delay(500);
   digitalWrite(D7, LOW);
 // We want internal pullup enabled:
 pinMode(int0_pin, INPUT);
 // When IR detected, Axman detector emits 5V
 attachInterrupt(0, blink, RISING);
 // initialize serial communication:
 //Serial.begin(9600);
 display.setTextSize(1.2);
  display.setTextColor(WHITE);
  display.setCursor(7,7);
  display.print("Power Consumption!");
  

  // update display with all of the above graphics
  display.display();
//  Serial.println("hello its working");
Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass);
 server.begin();
  Serial.print(WiFi.localIP());
  Serial.println("/");
 ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
   dateTime = NTPch.getNTPtime(1.0, 1);
    if(dateTime.valid){
 //   NTPch.printDateTime(dateTime);

    byte actualHour = dateTime.hour;
    byte actualMinute = dateTime.minute ;
    byte actualsecond = dateTime.second;
    int actualyear = dateTime.year;
    byte actualMonth = dateTime.month;
    byte actualday =dateTime.day;
    byte actualdayofWeek = dateTime.dayofWeek;
  
 actualHour=actualHour + 3;
 actualMinute=actualMinute+30;
 if(actualMinute>=59)
 {
  actualMinute=actualMinute-60;
  actualHour=actualHour + 1;
 }
  if(actualHour==12 && actualMinute==1)
 {
  ThingSpeak.writeField(525842,1, count ,apiKey);
  delay(5000);
 }
  }
 if (pulse_seen == 1) {
   count++;
   display.setTextSize(1.3);
  display.setTextColor(WHITE);
  
  display.clearDisplay();
  
 display.setTextSize(1.2);
  display.setTextColor(WHITE);
  display.setCursor(7,7);
  display.print("Power Consumption!");
   display.setTextSize(2);
  display.setCursor(30,27);
  display.print(count);
  display.print(" KWH");
   display.display();
Serial.println("interrupt seen \n");
Serial.println(count);
 //  last_pulse_time = millis();

   //if (counter == 1 || first_pulse_time == 0) // we were reset
     //first_pulse_time = last_pulse_time;

   // Blinky-blink
   digitalWrite(led_pin, HIGH);
   delay(500);
   digitalWrite(led_pin, LOW);
   // Reset until next one.
   pulse_seen = 0;
 }
}

void blink()
{
 static unsigned long last_interrupt_time = 0;
 unsigned long interrupt_time = millis();

 // If interrupts come faster than bounce_delay_ms, assume it's a bounce and ignore
 //
 // Note, millis() wraps every 50 days, be sure we cope...
 //
 if (interrupt_time - last_interrupt_time > 100)
   pulse_seen = 1;  // loop() sees pulse == 1 and takes action

 last_interrupt_time = interrupt_time;
}
