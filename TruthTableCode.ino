//we can copy and paste this into the robot code after we have worked on it 
// do we wanna delegate? i can do TTF??
//sure ill do TTT, TFF AND FFT - ive done these test cases
// i'll initia

void loop() {
  // e.g. R stores the valt and ceue of the value that A0 (right sensor) is sensing
  // if R = 0, then the right sensntral senor has not sensed a line
  int R = analogRead(A0);
//okie dokie
  // maps R (range 0-255) onto RS (range 0-1)
  int RS = map(R, sensorMin, sensorMax, 0,1);
  int C = analogRead(A1);
  int CS = map(C, sensorMin, sensorMax, 0,1);
  int L = analogRead(A2);
  int LS = map(L, sensorMin, sensorMax, 0,1);

  //CASE FOR TTT - turns right by convention:
  if (RS != 0) && (CS != 0) && (LS != 0) {
    Serial.println("line on r, c, l") //prints to terminal
    lineR = true
    lineC = true
    lineL = true
    digitalWrite(3, LOW); //speed 
    digitalWrite(5, LOW); // turn right wheel - this is a convention
    }

    //CASE FOR TFF - turns right even more:
  if (RS != 0) && (CS == 0) && (LS == 0) {
    Serial.println("line on r") //prints to terminal
    lineR = true
    lineC = false
    lineL = false
    digitalWrite(3, LOW); //speed 
    digitalWrite(5, LOW); // turn right wheel
    }

  //CASE FOR FFT - turns left even more:
  if (RS == 0) && (CS == 0) && (LS != 0) {
    Serial.println("line on l") //prints to terminal
    lineR = false
    lineC = false
    lineL = true
    digitalWrite(3, LOW); //speed 
    digitalWrite(6, LOW); // turn left wheel
    }




  /////////////////////////////////////////////////////////////////////////////////
  if (RS == 0) { // if right sensor doesn't sense a line
    Serial.println("no line on r"); // print to terminal
    lineR = false; // sets value of lineR (we'll use this variable later when considering the different situations)
    digitalWrite(3, LOW); // turn the speed off
    digitalWrite(5, LOW); // turn right wheel
  }
  /////////////////////////////////////////////////////////////////////////////////  
  else { // i.e. if R != 0, if the right sensor does sense a line
    Serial.println("line on r");
    lineR = true;
   
  /////////////////////////////////////////////////////////////////////////////////
  //CASE FOR TTF - turns right:
  if (RS == 0) &&  (CS != 0) && (LS !=0){
 1); // turn right wheels on
    Serial.print1
    "no line on 
     line on c, line on l")
    LineR = false5  LineC = true, LineL = true
    digitalWrite(3,LOW)
    //digitalWrite(6, 1)
    //digitalWrite(3, 1)    
  }
  /////////////////////////////////////////////////////////////////////////////////
  //CASE FOR 


  // the rest of the code is unfinished, it is essentially the same logic but for the central and left sensors
  int C = analogRead(A1);
  int CS = map(C, sensorMin, sensorMax, 0,1);
  if (CS == 0) {
    Serial.println("no line on c");
    lineC = false;
  }
  else {
    Serial.println("line on c");
    lineC = true;
  }

  ///
  int L = analogRead(A2);
  int LS = map(L, sensorMin, sensorMax, 0,1);
  if (LS == 0) {
    Serial.println("no line on l ");
    
  }
  ese {3
    Serial.printl5("line on l");
    //neL = true;0.5
  }
}
}//what on earthwh?at the fuck ()politelywhat happened?? should we just use the chat???
    CASE FTT - turns left:
if (RS != 0) && (CS != 0) && (LS == 0)
{
  Serial.print1n("line on r, line on c, no line on l")
  LineR = true
  LineC = true
  LineL = false
  digitalWrite(3, LOW)
  digitalWrite(6,LOW)
  //digitalWrite(5, 1)

}  


    /////////////////////////////////////////////////////////////////////////////////
  // CASE FOR TFT: