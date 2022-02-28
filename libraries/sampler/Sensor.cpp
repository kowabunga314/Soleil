

#include "Sensor.h"
// Import altimeter lib
#include "BMP085.h"

/* == Altimeter ==*/
// class default I2C address is 0x77
// specific I2C addresses may be passed as a parameter here
// (though the BMP085 supports only one address)
BMP085 barometer;
bool barometerConnected;


Sensor::Sensor() {}

// Set up altimeter
void Sensor::altimeterSetup() {
    // initialize device
    Serial.println("Initializing altimeter...");
    barometer.initialize();

    // verify connection
    Serial.println("Testing altimeter connection...");
    Serial.println(barometer.testConnection() ? "BMP085 connection successful" : "BMP085 connection failed");
    barometer.testConnection() ? barometerConnected = true : barometerConnected = false;
}

BarometerData Sensor::altimeterLoop() {

    // Don't read from sensor if not connected
    if (!barometerConnected) {
      Serial.println("Barometer not connected!");
      return;
    }

    // Get current timestamp
    this->bd.timestamp = micros();

    // request temperature
    barometer.setControl(BMP085_MODE_TEMPERATURE);
    
    // read calibrated temperature value in degrees Celsius
    this->bd.temperature = barometer.getTemperatureC();

    // request pressure (3x oversampling mode, high detail, 23.5ms delay)
    barometer.setControl(BMP085_MODE_PRESSURE_3);

    // read calibrated pressure value in Pascals (Pa)
    this->bd.pressure = barometer.getPressure();

    // calculate absolute altitude in meters based on known pressure
    // (may pass a second "sea level pressure" parameter here,
    // otherwise uses the standard value of 101325 Pa)
    this->bd.altitude = barometer.getAltitude(this->bd.pressure);

    // display measured values if appropriate
    // Serial.print("T/P/A\t");
    // Serial.print(this->bd.temperature); Serial.print("\t");
    // Serial.print(this->bd.pressure); Serial.print("\t");
    // Serial.print(this->bd.altitude);
    // Serial.println("");
    
    return bd;
}
