


//BRENDAN O BOYLE
//LAB 5
//CLASS FOR THE SERVO
#include <Servo.h>

class servoActuator {

  private:
    byte PIN_SERVO;
    unsigned long timeOn;
    Servo motor;

  public:
    //class constructor
    servoActuator(byte PIN_SERVO, unsigned long timeOn) {
      pinMode(PIN_SERVO, OUTPUT);
      this->PIN_SERVO = PIN_SERVO;
      this->timeOn = timeOn;
    }

    void ServoPosition(int angle) {
      motor.attach(PIN_SERVO);
      angle = map(angle, 0, 1023, 0, 180);
      motor.write(angle);
      delay(9);

    }

};
