
#include "sampler.h"


uint32_t sampleRate = 2;
Sampler sampler;
uint32_t lastMicros;

void setup() {
    setupSerial();
    Serial.println("Beginning initialization routine...");
    sampler = Sampler(sampleRate);
    sampler.initialize();
    Serial.println("Initialization complete.");
}

void loop () {
    // Serial.println("Sampling sensors...");
    lastMicros = sampler.takeSample();
     Serial.print("Took sample at ");
     Serial.println(lastMicros);
}

// Set up Serial connection`
void setupSerial() {

    // Initialize serial communication
    Serial.begin(115200);
    // Wait for Serial to start
    while (!Serial);

}
