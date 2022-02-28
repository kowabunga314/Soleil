
#ifndef SENSOR_H
#define SENSOR_H

#include "Arduino.h"

struct BarometerData {
  uint32_t timestamp;
  float temperature;
  float pressure;
  uint32_t altitude;
};

class Sensor {
  
  BarometerData bd;

  public:
    Sensor();
    void altimeterSetup();
    BarometerData altimeterLoop();
};

#endif