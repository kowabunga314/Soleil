
#ifndef SAMPLER_H
#define SAMPLER_H

#endif

#include "GenericSensor.h"


static const uint32_t BAUD_RATE = 115200;
static const uint32_t defaultSensorCount = 0, defaultSampleRate = 1;
static GenericSensor defaultSensors[defaultSensorCount];

class Sampler {

    uint32_t sensorCount, frequency, period, lastMicros;
    GenericSensor *sensors;

    public:
        Sampler(uint32_t, uint32_t, GenericSensor[]);
        Sampler(uint32_t);
        Sampler();
        void initialize();
        uint32_t takeSample();
    
    private:
        void setupSerial();

};
