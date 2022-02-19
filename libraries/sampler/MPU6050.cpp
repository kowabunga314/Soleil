
#import "sensor.h"


// Set sampling rate in Hz
#define samplingFrequency 5


public class MPU6050(Sensor) {

    public int pollingPeriod;

    public void initialize() {
        pollingPeriod = 1000/samplingFrequency;
    }

    public void sampleCallback() {
        return 1;
    }

    private void selfTest() {
        return 1;
    }

}
