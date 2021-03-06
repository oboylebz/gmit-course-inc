//BRENDAN O BOYLE
//LAB 5
//MAIN
//define pins used
#define PIN_LED1 3
#define PIN_SENSOR A1
#define PIN_SERVO 9



//object classes
Blinker blink1 = Blinker (PIN_LED1, 500, 500);
depthSensor depth = depthSensor(PIN_SENSOR);
servoActuator mov (PIN_SERVO, 1);
void setup() {
  Serial.begin(9600);//open the serial port at 9600 bps:
}

void loop() {
  blink1.check();//Calls in LED blink program
  depth.check();//Calls in Depth sensor program
  Serial.print(depth.getValue());//print voltage reading
  Serial.print(" ");
  mov.ServoPosition(depth.getsensorValue());//move servo to corospond to depth sensor value
}
