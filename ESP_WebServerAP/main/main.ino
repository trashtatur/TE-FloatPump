#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "floodSensor-AP";
const char* password = "flood";
const short pinISR = 13; // D7
bool state = false;
char* wifiSSID;
char* wifiPass;


ESP8266WebServer server(80);

void floodISR() {

}

void handleRoot() {
  server.send(200, "text/plain", "hello from esp8266!");
}

void handleNotFound(){

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

}

void setup(void){
    pinMode(pinISR, INPUT_PULLDOWN_16);
    pinMode(5, OUTPUT);
    delay(10);
    attachInterrupt(digitalPinToInterrupt(pinISR), floodISR, RISING);    
    delay(10);   
    Serial.begin(115200);
    
    if (state){
      WiFi.begin(wifiSSID, wifiPass);
      Serial.print("Connecting");
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
      Serial.println();   
      Serial.print("Connected, IP address: ");
      Serial.println(WiFi.localIP());
    }else {
      Serial.println();
      Serial.println("Configuring access point...");
      /* You can remove the password parameter if you want the AP to be open. */
      WiFi.softAP(ssid);
  
      IPAddress myIP = WiFi.softAPIP();
      Serial.print("AP IP address: ");
      Serial.println(myIP);
      server.on("/", handleRoot);
      server.onNotFound(handleNotFound);
      server.on("/inline", [](){
      server.send(200, "text/plain", "this works as well");
      });
      delay(4000);
      server.begin();
      Serial.println("HTTP server started");
      }
}

void loop(void){

    while(WiFi.softAP(ssid)){
       server.handleClient();
    }
    
}
