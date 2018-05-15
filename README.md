# TE-FloatPump

## Potential solutions

### 1. force sensor

The princept behind this solution is to measure two decetral Forcesensors. If one of those sensors is covert under water, the mass of the water in combination with the field of gravitiy will lead to an force delta between the two sensors. This event can be used as a trigger to start the pump as well as sending an SMS. 

### 2. humidity sensor with ESP8266

The Circuit

The Circuit is a simple …. – Circuit. It´s source is a 9V battery. If the humidity contacts aren´t connected due to water, no current flows. If the humidity contacts getting in contact with water, the transistors T1 and T2 are switched by the now closed circuit. When the Transistor T2 is switched, the current also flows in the “relay Circuit”, the LED lights up and the relay switches. The relay is able to switch up to 24V and 1A. It is either possible connect it with a small pump or connecting another relay which is able to switch more voltage and connect a larger pump. 
The ESP8266 is connected after the Transistor T2, it reads a Digital Input. If the Voltage change from a low – level to a high – level. The ESP8266 will send an e-Mail.

### 3. ToDo

## Andy 

Webserver 
  -> WebForm (keep in mind no filesystem use variables instead)
  -> emailSend
  
## Tobi

WiFi
  -> AP submit, then as Client
  -> müC adden

## TBD
 
 Präsi


### Referenz

https://arduino-esp8266.readthedocs.io/en/2.4.1/

https://www.kloppenborg.net/images/blog/esp8266/esp8266-node-mcu-pinout.png

http://www.instructables.com/id/ESP8266-GMail-Sender/
