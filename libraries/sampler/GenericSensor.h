
#include "sensor.h"


class GenericSensor: public Sensor {

  public:
    void initialize();
    double* readSensor();

  private:
    void selfTest();

};
