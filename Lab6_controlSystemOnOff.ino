#include <PID_v1.h>

//BRENDAN O BOYLE
//LAB 6
//MAIN
//define pins used

#define PIN_SENSOR A1
#define PIN_Light 9
#define PIN_INPUT 0
#define PIN_OUTPUT 3
 


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
//Define Variables we'll be connecting to
double Setpoint, Input, Output;
//Specify the links and initial tuning parameters
double Kp=2, Ki=5, Kd=1;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
 

void setup() {
  Serial.begin(9600);//open the serial port at 9600 bps:
   //initialize the variables we're linked to
 Input = analogRead(PIN_INPUT);
 Setpoint = 100;
 
 //turn the PID on
 myPID.SetMode(AUTOMATIC);
}

void loop() {
  
  Light.check();//Calls in Light sensor program
  Serial.println(Light.getValue());//print voltage reading
  Serial.print(" ");
  if (Light.getValue() >=2){//If the voltage from the light sensor is greater than 2v turn realy off
    digitalWrite(PIN_Light,LOW);}
    else{
      digitalWrite(PIN_Light,HIGH);//If the voltage from the light sensor is less than 2v turn realy on
    }
     Input = analogRead(PIN_INPUT);
 myPID.Compute();
 analogWrite(PIN_OUTPUT, Output);
  }



 




 
