  //Final Lab
  //Brendan O Boyle
  //Stepper Motor Class
  //23.04.21
  
  class aStepper {
  public:
  
  byte pinA;
  byte pinB;
  byte pinC;
  byte pinD;
  
   aStepper(byte pinA, byte pinB, byte pinC, byte pinD){
        
      pinMode(pinA,OUTPUT);
      pinMode(pinB,OUTPUT);
      pinMode(pinC,OUTPUT);
      pinMode(pinD,OUTPUT);
      }

  void CW(int d,int c,int b,int a){
      digitalWrite(pinA,a);
      digitalWrite(pinB,b);
      digitalWrite(pinC,c);
      digitalWrite(pinD,d);
      }
 
  void CCW(int a,int b,int c,int d){
      digitalWrite(pinA,a);
      digitalWrite(pinB,b);
      digitalWrite(pinC,c);
      digitalWrite(pinD,d);
       }
  

  void rotateCW(int delayValue){  
      CW(1,0,0,0);
      delay(delayValue);
      CW(1,1,0,0);
      delay(delayValue);
      CW(0,1,0,0);
      delay(delayValue);
      CW(0,1,1,0);
      delay(delayValue);
      CW(0,0,1,0);
      delay(delayValue);
      CW(0,0,1,1);
      delay(delayValue);
      CW(0,0,0,1);
      delay(delayValue);
      CW(1,0,0,1);
      delay(delayValue);
  }
   void rotateCCW(int delayValue){  
      CCW(1,0,0,0);
      delay(delayValue);
      CCW(1,1,0,0);
      delay(delayValue);
      CCW(0,1,0,0);
      delay(delayValue);
      CCW(0,1,1,0);
      delay(delayValue);
      CCW(0,0,1,0);
      delay(delayValue);
      CCW(0,0,1,1);
      delay(delayValue);
      CCW(0,0,0,1);
      delay(delayValue);
      CCW(1,0,0,1);
      delay(delayValue);
  }
  };
