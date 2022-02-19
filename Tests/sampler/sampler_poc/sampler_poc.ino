
#define INTERVAL 5000 // 5 milliseconds per sample for 200 Hz, change this for different sampling rates.
// #define INTERVAL 10000
// #define INTERVAL 500
// #define INTERVAL 1000000


unint32_t lastMicros = 0;


void setup() {
    setupSerial();
    Serial.println("Beginning initialization routine...");
    sampler.initialize(1);
    Serial.println("Initialization complete.");
}

void loop() {
  if (micros() - lastMicros > INTERVAL) {
    lastMicros = micros(); // do this first or your interval is too long!
    Serial.print("Took sample at ");
    Serial.println(lastMicros);
  }
}

// Set up Serial connection`
void setupSerial() {

    // Initialize serial communication
    Serial.begin(115200);
    // Wait for Serial to start
    while (!Serial);

}
