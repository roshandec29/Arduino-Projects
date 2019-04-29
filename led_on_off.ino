#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
const char *ssid =  "Udbhav";
const char *pass =  "roshan123";
//const char * apiKey = "AECYZQAVWPOBMH68";
//const char* server1= "api.thingspeak.com";
int ledPin =D3; // GPIO13
int ledpin1=D4;
int ledpin2=D5;
int ledpin3=D6;
unsigned long channel = 525842;
WiFiServer server(80);
//WiFiClient client;

void setup() 
{
       Serial.begin(9600);
       delay(10);
       
        
       pinMode(ledPin, OUTPUT);
       pinMode(ledpin1, OUTPUT);
       pinMode(ledpin2, OUTPUT);
       pinMode(ledpin3, OUTPUT);
       digitalWrite(ledPin, LOW);
       
       Serial.println("Connecting to ");
       Serial.println(ssid);
 WiFi.begin(ssid, pass);
 server.begin();
  Serial.print(WiFi.localIP());
  Serial.println("/");
// ThingSpeak.begin(client);
}
void loop() {
 // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) 
  {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  int value = LOW;
 
  if (request.indexOf("/LED=ON") != -1)  {
    digitalWrite(ledPin, HIGH);
    value = 1;
  }
  if (request.indexOf("/LED=OFF") != -1)  {
    digitalWrite(ledPin, LOW);
    value = 0;
  }
  if (request.indexOf("/LED1=ON") != -1)  {
    digitalWrite(ledpin1, HIGH);
    value = 1;
  }
  if (request.indexOf("/LED1=OFF") != -1)  {
    digitalWrite(ledpin1, LOW);
    value = 0;
  }
  if (request.indexOf("/LED2=ON") != -1)  {
    digitalWrite(ledpin2, HIGH);
    value = 1;
  }
  if (request.indexOf("/LED2=OFF") != -1)  {
    digitalWrite(ledpin2, LOW);
    value = 0;
  }
  if (request.indexOf("/LED3=ON") != -1)  {
    digitalWrite(ledpin3, HIGH);
    value = 1;
  }
  if (request.indexOf("/LED3=OFF") != -1)  {
    digitalWrite(ledpin3, LOW);
    value = 0;
  }
  
  client.println("<html><body align='Center'>");
 client.print("<h1>HOME AUTOMATION SYSTEM </h1> <br>");
  client.print("<h3>LIGHT is now: </h3>");
 
  if(value == 1) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button style='background-color:black;color:white;padding:20px;'>Turn On Bulb</button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button  style='background-color:black;color:white;padding:20px;'>Turn Off Bulb </button></a><br />");  
  client.println("<a href=\"/LED1=ON\"\"><button  style='background-color:black;color:white;padding:20px;'>Turn On CFL </button></a>");
  client.println("<a href=\"/LED1=OFF\"\"><button  style='background-color:black;color:white;padding:20px;'>Turn Off CFL </button></a><br />"); 
  client.println("<a href=\"/LED2=ON\"\"><button  style='background-color:black;color:white;padding:20px;'>Turn On Fan</button></a>");
  client.println("<a href=\"/LED2=OFF\"\"><button  style='background-color:black;color:white;padding:20px;'>Turn Off Fan</button></a><br />"); 
  client.println("<a href=\"/LED3=ON\"\"><button  style='background-color:black;color:white;padding:20px;'>Turn On Light</button></a>");
  client.println("<a href=\"/LED3=OFF\"\"><button  style='background-color:black;color:white;padding:20px;'>Turn Off Light</button></a><br />"); 
  client.print("<br><br> ");
  client.print("<hr align='Center' width='45%'>");
//  ThingSpeak.writeField(525842,1, value ,apiKey);
//  delay(5000);
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
  
}

