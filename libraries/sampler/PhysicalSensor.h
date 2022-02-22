
#include "GenericSensor.h"


class PhysicalSensor: public GenericSensor {

  int sensorId;

  public:
    void initialize();
    double* readSensor();

  private:
    int selfTest();

};
