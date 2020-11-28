void setup() {
  // put your setup code here, to run once:
  long timeNow = 0; // Hold the milliseond value for now
  long timer = 0; //general purpuse timer



  void loop() //Main Loop{

  long timeNow = millis(5);
  if ((timeNow - timer) >= 200) // Observe and change as required
  {
    timer = timeNow;
    Serial.println(timeNow);
    //CALL your function etc
  }
}
