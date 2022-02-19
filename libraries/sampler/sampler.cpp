
#include "sampler.h"



Sampler::Sampler() {
    ;
}

Sampler::initialize (uint sampleRate) {
    frequency = sampleRate;
    interval = 1000 - frequency;
}

Sampler::takeSample () {

    // Wait until we can perform the next sample
    while (micros() - lastMicros < interval);

    // update lastMicros immediately
    lastMicros = micros();

    // Let monitor know sample was taken
    Serial.print('Took sample at ');
    Serial.println(lastMicros);

}

// Set up Serial connection
Sampler::setupSerial() {

    // Initialize serial communication
    Serial.begin(BAUD_RATE);
    // Wait for Serial to start
    while (!Serial);

}
