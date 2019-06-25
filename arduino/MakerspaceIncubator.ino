/*********************************************************************
* MakerspaceIncubator.ino
* 
* Copyright (C)    2019   St Peters Mbare IoT Makerspace
* 
* GitHub Link :https://github.com/st-peters-mbare-iot-makerspace/makerspace-incubator
* This Library is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
*
*
* Hardware platform   : Arduino Bluno
* Sensors
* 1. DHT11
* 
* 
* Actuators
* 1. EGG TURNER 
* 2. FAN
*
* Author  :  St Peter Mbare IoT Makerspace
* Version :  V1.0
* Date    :  2019-06-25
**********************************************************************/

#include <dht.h>

dht DHT;
String values;

char charValueFloat[10];

#define DHT11_PIN 7

#define TEMP_LED_GREEN 6
#define TEMP_LED_RED 5

#define HUMI_LED_GREEN 8
#define HUMI_LED_RED 9

#define RELAY_PIN 10

int relayState = HIGH;
int lastRelayState = HIGH;

int temperatureState;
int lastTemperatureState=LOW;

int humidityState;
int lastHumidityState=LOW;

long lastDebounceTime=0;
long debounceDelay=50;

String tempString;
String humiString;
/*Hatching Temperature: 35 - 40.5 Degrees Celsius */
/*Hatching Humidity: 60 - 75% */

void setup(){
  pinMode(TEMP_LED_GREEN, OUTPUT);
  pinMode(TEMP_LED_RED, OUTPUT);
  pinMode(HUMI_LED_GREEN, OUTPUT);
  pinMode(HUMI_LED_RED, OUTPUT);
  Serial.begin(112500);
}

void loop()
{
  const int bufferSize = 1048;
  char buf[bufferSize] = {'\0'};
  
  
  int chk = DHT.read11(DHT11_PIN);
  /*Reading the Temperature & Humidity*/
  float temperature = DHT.temperature;
  float humidity = DHT.humidity;
  
  

  // Check if any reads failed and exit early to try again.
  if (isnan(humidity) || isnan(temperature) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  int numChars = 0;

  numChars += sprintf(&buf[numChars], "{\"source\":\"arduino\",\"place\":\"lab\",");//JSON

  //converting floats to strings
  tempString=dtostrf( temperature, 4, 4, charValueFloat );
  humiString=dtostrf( humidity, 4, 4, charValueFloat );
  
  
  values = tempString+ ","+humiString;//+",arduino1";
  //values = humiString + ",arduino1";
  
  Serial.println(values);
  delay(3000);
  
  
}
