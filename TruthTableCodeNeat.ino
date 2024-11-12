
int R = analogRead(A0);
int RS = map(R, sensorMin, sensorMax, 0,1);
int C = analogRead(A1);
int CS = map(C, sensorMin, sensorMax, 0,1);
int L = analogRead(A2);
int LS = map(L, sensorMin, sensorMax, 0,1);

////////////////////////////////////////////////////////////////////////

//CASE FOR TTT - turns right by convention:
if (RS != 0) && (CS != 0) && (LS != 0) {
  Serial.println("line on r, c, l"); //prints to terminal
  lineR = true;
  lineC = true;
  lineL = true;
  digitalWrite(3, LOW); //speed 
  digitalWrite(5, LOW); // turn right wheel - this is a convention
  }
/////////////////////////////////////////////////////////////////////////////////

//CASE FOR TTF - turns right:
if (RS == 0) && (CS != 0) && (LS !=0){
  Serial.printIn("no line on r, line on c, line on l");
  LineR = false;
  LineC = true;
  LineL = true;
  digitalWrite(3,LOW);
  digitalWrite(5, LOW);   
}
/////////////////////////////////////////////////////////////////////////////////

//CASE FOR TFT - turns right by convention:
if (RS == 0) && (CS != 0) && (LS !=0){
  Serial.printIn("line on r, no line on c, line on l");
  LineR = true;
  LineC = false;
  LineL = true;
  digitalWrite(3,LOW);
  digitalWrite(5, LOW);   
}

////////////////////////////////////////////////////////////////////////

//CASE FOR TFF - turns right even more:
if (RS != 0) && (CS == 0) && (LS == 0) {
  Serial.println("line on r"); //prints to terminal
  lineR = true;
  lineC = false;
  lineL = false;
  digitalWrite(3, LOW); //speed 
  digitalWrite(5, LOW); // turn right wheel
  }

////////////////////////////////////////////////////////////////////////

//CASE FTT - turns left:
if (RS != 0) && (CS != 0) && (LS == 0){
  Serial.printIn("line on r, line on c, no line on l");
  LineR = true;
  LineC = true;
  LineL = false;
  digitalWrite(3, LOW);
  digitalWrite(6,LOW);
}  

//ftf
/////////////////////////////////////////////////////////////////////////////////

//CASE FOR FTF - keeps going straight:
if (RS == 0) && (CS != 0) && (LS == 0) {
  Serial.println("no line on r, line on c, no line on l");
  lineR = false;
  lineC = true;
  lineL = false;
  digitalWrite(3, LOW); //speed 
  digitalWrite(5, LOW); // right wheels
  digitalWrite(6, LOW); // left wheels
}

//CASE FOR FFT - turns left even more:
if (RS == 0) && (CS == 0) && (LS != 0) {
  Serial.println("line on l"); //prints to terminal
  lineR = false;
  lineC = false;
  lineL = true;
  digitalWrite(3, LOW); //speed 
  digitalWrite(6, LOW); // turn left wheel
  }
//CASE FOR FFF - runs in timed left n right:
if (RS == 0) && (CS == 0) && (LS == 0)
  Serial.println("no line detected") // prints to terminal
  lineR = false;
  lineC= false;
  lineL = false;
  digitalWrite(3, HIGH);
  digitalwrite(5, HIGH);
  digitalwrite(6, HIGH);
  delay(50);
  digitalwrite(6, HIGH);
  delay(50);
  digitalWrite(3, HIGH);
  delay(50);

}
