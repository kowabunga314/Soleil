
#include <Arduino.h>
#include "sampler.h"


void Sampler::initialize (uint32_t sampleRate) {

    // Initialize Serial stream
    Sampler::setupSerial();

    // Set class properties
    frequency = sampleRate;
    period = 1000 / frequency;
    Serial.print("Sampling at frequency: ");
    Serial.print(frequency);
    Serial.println("Hz.");
    Serial.print("Sampling interval: ");
    Serial.print(period);
    Serial.println(" milliseconds per sample.");
}

uint32_t Sampler::takeSample () {

    // Wait until we can perform the next sample
    while (micros() - Sampler::lastMicros < period);

    // update lastMicros immediately
    Sampler::lastMicros = micros();

    // Let monitor know sample was taken
    return Sampler::lastMicros;

}

// Set up Serial connection
void Sampler::setupSerial() {

    // Initialize serial communication
    Serial.begin(115200);
    // Wait for Serial to start
    while (!Serial);

}
