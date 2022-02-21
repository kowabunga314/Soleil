
#include <Arduino.h>
#include "sampler.h"
// #include "sensor.h"


/*
 * Constructor for Sampler class with no sensors
 *  
 * @param sampleRate frequency with which samples are to be taken.
 */
// Sampler::Sampler(uint32_t sampleRate) {

//   // Initialize Serial stream
//   setupSerial();

//   Serial.print("sampleRate: ");
//   Serial.println(sampleRate);

//   frequency = 2;
// }

/*
 * Constructor for Sampler class
 *  
 * @param sensors an array of Sensor objects that are sampled
 *                periodically based on the sampleRate.
 * @param sensorArrayLength the length of the sensors array.
 * @param sampleRate frequency with which samples are to be taken.
 */
// Sampler::Sampler(Sensor newSensors[], uint32_t sensorArrayLength, uint32_t sampleRate) {
//   sensors = newSensors;
//   sensorCount = sensorArrayLength;
//   frequency = sampleRate;
// }

void Sampler::initialize (Sensor newSensors[], uint32_t sensorArrayLength, uint32_t sampleRate) {

    sensors = newSensors;
    sensorCount = sensorArrayLength;
    frequency = sampleRate;

    // Initialize Serial stream
    Sampler::setupSerial();

    // Set class properties
    period = 1000000 / frequency;
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

    // Update micros measurement
    uint32_t newMicros = micros();
    // Get time delta for sample
    uint32_t timeDelta = newMicros - lastMicros;
    // update lastMicros with latest measurement
    Sampler::lastMicros = newMicros;

    // Execute sensor callbacks
    // for (int pos; pos < sensorCount; pos++) {
    //   // Get callback for sensor at pos
    // }

    // Let monitor know sample was taken
    return lastMicros;

}

// Set up Serial connection
void Sampler::setupSerial() {

    // Initialize serial communication
    Serial.begin(BAUD_RATE);
    // Wait for Serial to start
    while (!Serial);

}
