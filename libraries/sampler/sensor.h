

class Sensor {

  public:
    virtual void initialize() = 0;
    virtual double* readSensor() = 0;

  private:
    void selfTest();

};
