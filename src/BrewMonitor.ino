/*
 * Project BrewMonitor
 * Description:
 * Author:
 * Date:
 */

#include "DS18.h"

double temp;
int historyRecords;
DS18 tempSensor(D6);
const int hoursToTrack = 12;
char history[hoursToTrack];
const system_tick_t pollPeriod = 250;
const system_tick_t pollPeriodForHistory = 3600000;
system_tick_t timeOfLastRead = 0;
system_tick_t timeOfLastReadForHistory = 0;

void setup()
{
  Particle.variable("temp", temp);
  Particle.variable("history", history);
  Particle.variable("historyRecords", historyRecords);

  for(int i = 0; i < hoursToTrack; i++)
  {
    history[i] = 0;
  }

  historyRecords = 0;
}

void loop()
{
  if (millis() - timeOfLastRead >= pollPeriod && tempSensor.read())
  {
    temp = tempSensor.fahrenheit();
    timeOfLastRead = millis();
  }

  if(millis() - timeOfLastReadForHistory >= pollPeriodForHistory)
  {
    for(int i = hoursToTrack - 1; i > 0; i--)
    {
      history[i] = history[i-1];
    }

    history[0] = (int)(temp);
    timeOfLastReadForHistory = millis();
    historyRecords++;
  }
}
