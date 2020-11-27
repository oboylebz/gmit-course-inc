  int led1 = 10;
  int led = 9 ;
  int brightness = 0;
  int fadeAmount = 5;
  // put your setup code here, to run once:
  void setup()
  {
  
    // declare pin 9 and 10 to be an output
    pinMode(led,OUTPUT);
    pinMode(led1,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //set the brightness of pin 9
  analogWrite ( led , brightness );
  analogWrite ( led1 , brightness);
  //change the brightness for the next time through the loop:
  brightness=brightness+fadeAmount;
  //reverse the direction at the end of fade:
  if ( brightness==0||brightness==255){
    fadeAmount=-fadeAmount;
  }
  //wait for 30ms to see the dimming effect
  delay(300);
  
  }
