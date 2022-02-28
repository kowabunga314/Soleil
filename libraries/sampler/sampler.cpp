
#include <Arduino.h>
#include "sampler.h"

#include "Sensor.h"


/*
 * Constructor for Sampler class with no sensors
 *  
 * @param sampleRate frequency with which samples are to be taken.
 * @param sensorCountArg number of sensors from which to collect data.
 */
Sampler::Sampler (uint32_t sampleRate, uint32_t sensorCountArg) {

  // Set frequency to given sampleRate
  frequency = sampleRate;
  // Set sensor count to given sensor count
  sensorCount = sensorCountArg;

  // Initialize sensor object
  sensor = Sensor();
}

/*
 * Constructor for Sampler class with no sensors
 *  
 * @param sampleRate frequency with which samples are to be taken.
 */
Sampler::Sampler (uint32_t sampleRate) {

  // Set frequency to given sampleRate
  frequency = sampleRate;

  // Set sensor count to default value
  sensorCount = defaultSensorCount;

  // Initialize sensor object
  sensor = Sensor();
}

/*
 * Constructor for Sampler class with no sensors
 */
Sampler::Sampler () {

  // Initialize Sampler using default values
  sensorCount = defaultSensorCount;
  frequency = defaultSampleRate;

  // Initialize sensor object
  sensor = Sensor();
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

    this->sensor.altimeterSetup();
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

    BarometerData bd = this->sensor.altimeterLoop();

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
