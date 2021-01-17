//myWiFiSensor.ino
//Import Libraries!
#include <SPI.h>
#include <WiFi.h>
#include <PubSubClient.h>
//#include <aJSON.h>
#include <stdio.h>
#include "Event.h"
//Events
Event myEvent;
//JSON Globals
Event wifiReady;//JSON Globals
//aJsonStream serial_stream(&Serial);

int light_val = 0;
int moisture = 0;

char moisture_str[10];
char light_str[10];


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly: 

}
