/*
 * Project BrewMonitor
 * Description:
 * Author:
 * Date:
 */

#include "DS18.h"

double temp;
DS18 tempSensor(D6);
const system_tick_t pollPeriod = 250;

void setup()
{
  Particle.variable("temp", temp);
}

void loop()
{
  system_tick_t timeOfLastRead = 0;
  if (millis() - timeOfLastRead >= pollPeriod && tempSensor.read())
  {
    temp = tempSensor.fahrenheit();
    timeOfLastRead = millis();
  }
}
