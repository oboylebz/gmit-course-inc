
//BRENDAN O BOYLE
//LAB 4
//CLASS FOR THE DEPTH SENSOR

class depthSensor {
  private:
    byte pinSensor;

   int val = 0 ;                           //variable to store the value read

  public:
      depthSensor(byte pinSensor) {
      this-> pinSensor = pinSensor;
      
pinMode (pinSensor, INPUT);               //Depth sensor is an input
    }


void loop() {                              // the loop routine runs over and over 
 int sensorValue = analogRead(A0);
 float voltage = sensorValue * (5.0 / 1023.0);
 float distance =-22.469*voltage+60.131;   // Distance on the graph in cm

void getValue(){
 Serial.print("X,"); Serial.print(distance); Serial.print(" ");
 Serial.println(" ");
 delay (600);
}
    
};
