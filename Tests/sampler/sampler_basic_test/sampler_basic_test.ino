
#include "sampler.h"
#include "Sensor.h"
#include <stdint.h>


uint32_t sampleRate = 1;
Sampler sampler;
BarometerData bd;

void setup() {
    setupSerial();
    Serial.println("Beginning initialization routine...");
    sampler = Sampler(sampleRate);
    
    sampler.initialize();
    Serial.println("Initialization complete.");
}

void loop () {
    // Serial.println("Sampling sensors...");
    bd = sampler.takeSample();

    Serial.print("A sample was taken at ");
    Serial.print(bd.timestamp);
    Serial.println(" us.");
    Serial.print("Barometer pressure reading: ");
    Serial.print(bd.pressure);
    Serial.println(" (pressure units).");
    Serial.print("Barometer temperature reading: ");
    Serial.print(bd.temperature);
    Serial.println(" degrees C.");
    Serial.print("Barometer altitude reading: ");
    Serial.print(bd.altitude);
    Serial.println(" meters.");
    Serial.println();
}

// Set up Serial connection`
void setupSerial() {

    // Initialize serial communication
    Serial.begin(115200);
    // Wait for Serial to start
    while (!Serial);

}
