#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
//Replace your wifi credentials here
const char* ssid     = "RK";
const char* password = "roshan123";
 
//change your channel number here
unsigned long channel = 525842;
 
//1,2 and 3 are channel fields. You don't need to change if you are following this tutorial. However, you can modify it according to your application
unsigned int led1 = 1;
WiFiClient  client;
 
 
void setup() {
  Serial.begin(115200);
  delay(100);
  
  pinMode(13, OUTPUT);
  // We start by connecting to a WiFi network
 
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  ThingSpeak.begin(client);
 
}
void loop() {

 
  //get the last data of the fields
  int led_1 = ThingSpeak.readFloatField(channel, led1);
 
  if(led_1 == 1){
    digitalWrite(13, 1);
    Serial.println("led is On..!");
  }
  if(led_1==0)
  {
    digitalWrite(13, 0);
    Serial.println("led is Off..!");
}
    
  Serial.println(led_1);
  delay(5000);
 
}
