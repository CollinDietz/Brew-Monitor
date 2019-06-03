/*
 * Project BrewMonitor
 * Description:
 * Author:
 * Date:
 */

#include "DS18.h"

double temp;
DS18 tempSensor(D6);

void setup() {
  Particle.variable("temp", temp);
}

void loop() {
  if (tempSensor.read()) {
   temp = tempSensor.fahrenheit();
   delay(250);
 }

}