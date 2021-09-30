/*!
 *  @file MQ135.cpp
 *
 *  Library Sensor MQ135 use with boards Arduino
 *  Air Quality check function
 *
 *  @section author Author
 *
 *  Written by TrungKuro
 *
 *  @section license License
 *
 *  Hshop license, all text above must be included in any redistribution
 */

#include "MQ135.h"

/*!
 *  @brief  Instantiates a new MQ135 class
 *  @param  pin
 *          Pin number that sensor is connected (note: use pin Analog)
 *  @param  isPower5v
 *          The sensor use logic 3.3v or 5v (default 5v)
 *  @param  res2
 *          The value Resistance R2 of sensor (default 2KOhm)
 */
MQ135::MQ135(uint8_t pin, bool isPower5v, float res2)
{
  _pin = pin;
  _isPower5v = isPower5v;
  _res2 = res2;
}

/////////////////////////////////////////////////////////////////////

/*!
 *  @brief  It will delay ~20s to heat probe sensor to ready
 *          Then calculate value RO based on RS
 */
void MQ135::begin()
{
  delay(19000);
  _resO=0;

  uint8_t count=10;
  uint8_t i=count;
  while (i--)
  {
    _resO += (MQ135::calculateRS()/AIR); // Calculate the average of RO (RO = RS/3.7)
    delay(100);
  }
  _resO /= (float)count;
}

/*!
 *  @brief  Read Air Quality
 *  @param  unit
 *          The unit (%)
 *          The unit default (ppm)
 */
void MQ135::readAirQuality(uint8_t unit)
{
  float RS = MQ135::calculateRS();
  
  air.max = 731.45 * pow(RS/_resO, -4.098) / (unit==PERCENT_AIR?10000.0:1.0);
  air.min = 32.84 * pow(RS/_resO, -3.99) / (unit==PERCENT_AIR?10000.0:1.0);
}

/////////////////////////////////////////////////////////////////////

/*!
 *  @brief  Calculate value RS based on R2 and level Logic with the value Analog voltage of sensor
 */
float MQ135::calculateRS()
{
  float sensorValue = analogRead(_pin);
  float sensorVolt = sensorValue * (_isPower5v?5.0:3.3) / (_isPower5v?1024.0:675.84);
  float RS = (_isPower5v?5.0:3.3) * _res2 / sensorVolt - _res2;

  return RS;
}
