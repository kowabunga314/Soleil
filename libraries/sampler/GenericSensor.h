
#include "sensor.h"


class GenericSensor: public Sensor {

  public:
    void initialize();
    void readSensor();

  private:
    void selfTest();

};
