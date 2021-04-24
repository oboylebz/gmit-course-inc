  //Final Lab
  //Brendan O Boyle
  //Stepper Motor
  //23.04.21
  
  #define PinA 4
  #define PinB 5
  #define PinC 6
  #define PinD 7
  #define PotInputPin A1
  #define CWButton 2
  #define CCWButton 3
  #define NUMBER_OF_STEPS_PER_REV 512
  

  int motorSpeed = 0;
  int CWButtonState = 0;
  int CCWButtonState = 0;
  aStepper rotate = aStepper(PinA ,PinB ,PinC ,PinD);
  
  void setup() {
      pinMode(CWButton,INPUT); 
      pinMode(CCWButton,INPUT);
  }
  
  void loop() {
    
      //Read the button state
      CWButtonState = digitalRead(CWButton);
      CCWButtonState = digitalRead(CCWButton);
        
      //when the button is pressed ButtonState goes High and motor rotates in a CW direction
      if(CWButtonState == HIGH){
      for(int i = 0;i < NUMBER_OF_STEPS_PER_REV; ++i){
        motorSpeed = analogRead(PotInputPin);
        float Speed = motorSpeed * (5.0/1023);
        rotate.rotateCW(Speed); 
          }
        }
        
       // when the button is pressed ButtonState goes High and the motor rotates in a CCW direction
       if(CCWButtonState == HIGH){
       for(int i = 0;i < NUMBER_OF_STEPS_PER_REV; ++i){
        motorSpeed = analogRead(PotInputPin);
        float Speed = motorSpeed * (5.0/1023);
        rotate.rotateCCW(Speed);    
          }
        }
  }
