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

#ifndef MQ135_H
#define MQ135_H

#include <Arduino.h>

#define AIR 3.7 // The RS/R0 ratio is a constant 3.7 in "clean air"

/* Define types Unit of MQ-135 */
#define PERCENT_AIR 1 // Percent Air Quality (%)
#define PPM 2         // Parts Per Million (ppm)

class MQ135
{
public:
  MQ135(uint8_t pin, bool isPower5v=true, float res2=2000);

  struct airQuality
  {
    float max=0;
    float min=0;
  } air;

  void begin();
  void readAirQuality(uint8_t unit=PPM); // Unit default (ppm), based on ratio RS/RO

private:
  uint8_t _pin;
  float _res2, _resO;
  bool _isPower5v;

  float calculateRS();
};

#endif
