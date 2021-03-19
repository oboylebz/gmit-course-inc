//BRENDAN O BOYLE
//LAB 6
//MAIN
//define pins used

#define PIN_SENSOR A1
#define PIN_Light 9


class LightSensor {
  private:
    byte pinSensor;
    unsigned long nextChangeTime = 0;
    // int sensorValue = 0 ;                           //variable to store the value read
    float voltage ;

  public:
    int sensorValue = 0 ;
    LightSensor(byte pinSensor) {
      this-> pinSensor = pinSensor;

      pinMode (pinSensor, INPUT);               //Light sensor is an input
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

//object classes

LightSensor Light = LightSensor(PIN_SENSOR);

void setup() {
  Serial.begin(9600);//open the serial port at 9600 bps:
}

void loop() {
  
  Light.check();//Calls in Light sensor program
  Serial.print(Light.getValue());//print voltage reading
  Serial.print(" ");
  if (Light.getValue() >=2){//If the voltage from the light sensor is greater than 2v turn realy off
    digitalWrite(PIN_Light,LOW);}
    else{
      digitalWrite(PIN_Light,HIGH);//If the voltage from the light sensor is less than 2v turn realy on
    }
  }
