
#ifndef SAMPLER_H
#define SAMPLER_H

#endif


const uint32_t BAUD_RATE = 115200;

class Sampler {

    uint32_t frequency, period, lastMicros;

    public:
        void initialize(uint32_t);
        uint32_t takeSample();
    
    private:
        void setupSerial();

};
