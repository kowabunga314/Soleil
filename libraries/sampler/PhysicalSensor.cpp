
#include "PhysicalSensor.h"


void PhysicalSensor::initialize() {
  ;
}

double* PhysicalSensor::readSensor() {
  double foo = 1.0 * selfTest();
  double sensorIds[1] = { foo };
  return sensorIds;
}

int PhysicalSensor::selfTest() {
  return sensorId;
}
