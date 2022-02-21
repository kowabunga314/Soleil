

class Sensor {

  public:
    virtual void initialize() = 0;
    virtual void readSensor() = 0;

  private:
    void selfTest();

};
