
#ifndef SAMPLER_H
#define SAMPLER_H

#define BAUD_RATE = 115200


class Sampler {

    uint frequency, period, lastMicros;

    public:
        void initialize(uint)
        void takeSample();
    
    private:
        void setupSerial();

}
