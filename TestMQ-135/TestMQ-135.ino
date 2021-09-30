#include <MQ135.h>

#define MQ_PIN A0

MQ135 mq(MQ_PIN, false, 1000); // Here I use sensor have logic 3.3v (isPower5v=false) and R2=1kOhm (default 2kOhm)

void setup()
{
  Serial.begin(9600);
  Serial.print(F("MQ135 test!\n"));
  Serial.print(F("Please wait for the sensor probe to warm up (~20s)\nThe program is calculating the value of RO..."));
  mq.begin();
  Serial.print(F("ready\n"));
}

void loop()
{
  mq.readAirQuality(PERCENT_AIR); // Unit (%)
  Serial.print(F("Level Air Quality: ["));
  Serial.print(mq.air.min, 2);
  Serial.print(F(" - "));
  Serial.print(mq.air.max, 2);
  Serial.print(F("] %\n"));
  
  delay(1000);
}
