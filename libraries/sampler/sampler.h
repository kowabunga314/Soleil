
#ifndef SAMPLER_H
#define SAMPLER_H

#endif

#include "sensor.h"


static const uint32_t BAUD_RATE = 115200;

class Sampler {

    uint32_t sensorCount, frequency, period, lastMicros;
    Sensor *sensors;

    public:
        void initialize(Sensor[], uint32_t, uint32_t);
        uint32_t takeSample();
    
    private:
        void setupSerial();

};
