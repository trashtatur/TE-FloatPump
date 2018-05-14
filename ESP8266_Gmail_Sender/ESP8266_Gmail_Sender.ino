#include <ESP8266WiFi.h>
#include "Gsender.h"

#pragma region Globals
const char* ssid = "Spinnen Spot";                           // WIFI network name
const char* password = "12345678";                       // WIFI network password
uint8_t connection_state = 0;                    // Connected to WIFI or not
uint16_t reconnect_interval = 10000;             // If not connected wait time to try again
#pragma endregion Globals

const byte ledPin = 13;
const byte interruptPin = 2; // D04
volatile short state = 0;

uint8_t WiFiConnect(const char* nSSID = nullptr, const char* nPassword = nullptr)
{
    static uint16_t attempt = 0;
    Serial.print("Connecting to ");
    if(nSSID) {
        WiFi.begin(nSSID, nPassword);  
        Serial.println(nSSID);
    } else {
        WiFi.begin(ssid, password);
        Serial.println(ssid);
    }

    uint8_t i = 0;
    while(WiFi.status()!= WL_CONNECTED && i++ < 50)
    {
        delay(200);
        Serial.print(".");
    }
    ++attempt;
    Serial.println("");
    if(i == 51) {
        Serial.print("Connection: TIMEOUT on attempt: ");
        Serial.println(attempt);
        if(attempt % 2 == 0)
            Serial.println("Check if access point available or SSID and Password\r\n");
        return false;
    }
    Serial.println("Connection: ESTABLISHED");
    Serial.print("Got IP address: ");
    Serial.println(WiFi.localIP());
    return true;
}

void Awaits()
{
    uint32_t ts = millis();
    while(!connection_state)
    {
        delay(50);
        if(millis() > (ts + reconnect_interval) && !connection_state){
            connection_state = WiFiConnect();
            ts = millis();
        }
    }
}

void setup()
{ 
  
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);
    pinMode(interruptPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(interruptPin), floodISR, RISING);    
    connection_state = WiFiConnect();
    
    if(!connection_state)  // if not connected to WIFI
        Awaits();          // constantly trying to connect    
}

//ISR
void floodISR() {
    state++;
    Serial.println(state);
}

void loop(){
  
  digitalWrite(ledPin, state);
 //Serial.println(state);
  if (state > 0){
      Gsender *gsender = Gsender::Instance();    // Getting pointer to class instance
      String subject = "YOUR CELLAR IS ABOUT TO GET KEVIN COSTNER WATERWOLDED!";
      
      if(gsender->Subject(subject)->Send("boris.on@live.com", "Does it work???")) {
          Serial.println("Message send.");
      } else {
          Serial.print("Error sending message: ");
          Serial.println(gsender->getError());
      }
      state--;
  }
  
   
}
