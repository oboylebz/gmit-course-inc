//BRENDAN O BOYLE
//LAB 4
//MAIN 

#define PIN_LED1 3
#define  PIN_SENSOR A0

Blinker blink1 = Blinker (PIN_LED1, 500, 500);
depthSensor depth = depthsensor(PIN_SENSOR ,A0);

void setup() {
Serial.begin(9600);
}

void loop() {
  blink1.check();
 depth.check();
Serial.print(depth.getValue());
Serial.print(" ");

}
