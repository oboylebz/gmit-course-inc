
//BRENDAN O BOYLE
//LAB 5
//CLASS FOR THE DEPTH SENSOR

class depthSensor {
  private:
    byte pinSensor;
    unsigned long nextChangeTime = 0;
    // int sensorValue = 0 ;                           //variable to store the value read
    float voltage ;

  public:
    int sensorValue = 0 ;
    depthSensor(byte pinSensor) {
      this-> pinSensor = pinSensor;

      pinMode (pinSensor, INPUT);               //Depth sensor is an input
    }


    void calculate() {                              // the loop routine runs over and over
      this-> sensorValue = analogRead(pinSensor);
      this-> voltage = sensorValue * (5.0 / 1023.0);


    }
    float getValue() {
      return voltage;
    }
    void check() {
      unsigned long currentTime = millis();

      if (currentTime >= nextChangeTime) {
        calculate();

        nextChangeTime = currentTime + 20;
      }
    }
    int getsensorValue() {//
      return sensorValue;

    }

};
