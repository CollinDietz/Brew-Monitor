/*
 * Project BrewMonitor
 * Description:
 * Author:
 * Date:
 */

#include "DS18.h"

double temp;
DS18 tempSensor(D6);

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(D7, OUTPUT);
  digitalWrite(D7, HIGH);

  Particle.variable("temp", temp);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.

  if (tempSensor.read()) {
   temp = tempSensor.fahrenheit();
   delay(1000);
 }

}