
#include <Arduino.h>
#include "sampler.h"



/*
 * Constructor for Sampler class
 *  
 * @param sampleRate frequency with which samples are to be taken.
 * @param sensors an array of Sensor objects that are sampled
 *                periodically based on the sampleRate.
 * @param sensorArrayLength the length of the sensors array.
 */
Sampler::Sampler (uint32_t sampleRate, uint32_t sensorArrayLength, GenericSensor newSensors[]) {
  sensors = newSensors;
  sensorCount = sensorArrayLength;
  frequency = sampleRate;
}

/*
 * Constructor for Sampler class with no sensors
 *  
 * @param sampleRate frequency with which samples are to be taken.
 */
Sampler::Sampler (uint32_t sampleRate) {

  // Set frequency to given sampleRate
  frequency = sampleRate;

  // Initialize Sampler using default values
  sensors = defaultSensors;
  sensorCount = defaultSensorCount;
}

/*
 * Constructor for Sampler class with no sensors
 *  
 * @param sampleRate frequency with which samples are to be taken.
 */
Sampler::Sampler () {

  // Initialize Sampler using default values
  sensors = defaultSensors;
  sensorCount = defaultSensorCount;
  frequency = defaultSampleRate;
}

void Sampler::initialize () {

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
