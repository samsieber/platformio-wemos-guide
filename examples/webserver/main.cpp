#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

// You'll want to use the ssid and password of whatever network you want the esp8266 to connect to;
const char* ssid = "******";
const char* password = "******";

// The mdns responder lets you access the esp8266 through a hostname, not just an ip
// It lets the esp8266 publish the name that should be associated with it.
MDNSResponder mdns;

// Creates a new server on port 80
// It's not running yet though
ESP8266WebServer server(80);

const int led = BUILTIN_LED;
uint8_t LED_ON = LOW;
uint8_t LED_OFF = HIGH;

// This a handler we can attach to our server
// Since the server is synchronous, the api is to write responses on the server object
// Here we blink the LED on whilst processing a request
void handleRoot() {
  digitalWrite(led, LED_ON);
  server.send(200, "text/plain", "hello from esp8266!");
  digitalWrite(led, LED_OFF);
}

// All request info is read from the server object as well.
void handleNotFound(){
  digitalWrite(led, LED_ON);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, LED_OFF);
}

void setup(void){
  pinMode(led, OUTPUT);
  digitalWrite(led, LED_OFF);
  // Note the serial rate - if you don't match it when connecting you'll get garbage.
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // This tells the network that you can access the ip address of the esp8266 via 'esp8266.local'
  // The first arg is the hostname - '.local' will be appended to it, the second arg is the ip address
  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }

  
  server.on("/", handleRoot);

  server.on("/inline", [](){
    server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  // This seems to be necessary - I don't know the specifics of why quite yet.
  server.handleClient();
}
