# MQ135 Air Quality Sensor Library
Library sensor MQ-135 for **boards Arduino**
<p align="center"><img src="/assets/mq-135.jpg"/></p>

## Constructors
```
MQ135(uint8_t pin, bool isPower5v=true, float res2=2000);
```
+ pin      : the pin Analog connect
+ isPower5v: the level logic of sensor (default 5v)
+ res2     : the resistor R2 base on Schematic (default 2kΩ)

## Methods

### Need calculate RO before used, wait ~20s
```
void begin();
```

### Calculate value, with unit selected
```
void readAirQuality(uint8_t unit=PPM);
```
+ unit: select unit, default (ppm)
  - PERCENT_AIR (%)
  - PPM         (ppm)

### Read value with range of Max/Min
```
+ air.max
+ air.min
```
