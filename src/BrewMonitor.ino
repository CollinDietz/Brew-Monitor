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
const int historyRecordsMax = 100;
double history[historyRecordsMax];
const int spacePerHistoryEntry = 6;
char historyString[historyRecordsMax * spacePerHistoryEntry];
const system_tick_t pollPeriod = 250;
const system_tick_t pollPeriodForHistory = 600000;
system_tick_t timeOfLastRead = 0;
system_tick_t timeOfLastReadForHistory = 0;

void setup()
{
  Particle.variable("temp", temp);
  Particle.variable("history", historyString);
  Particle.variable("historyRecords", historyRecords);

  for(int i = 0; i < historyRecordsMax; i++)
  {
    history[i] = 0;
    historyString[i] = 0;
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
    for(int i = historyRecordsMax - 1; i > 0; i--)
    {
      history[i] = history[i-1];
    }

    history[0] = temp;
    timeOfLastReadForHistory = millis();
    historyRecords++;

    int j = 0;
    for(int i = 0; i < std::min(historyRecordsMax, historyRecords); i++)
    {
      double val = history[i];

      sprintf(&historyString[j], "%.2f,", val);
      j+=6;
    }
  }
}
