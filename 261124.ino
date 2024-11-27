void setup() {
  Serial.begin(9600); // default bits per second rate

  // we will initialise each of the relevant pins for our robot
  // e.g., pin 3 is responsible for the speed of the robot

  pinMode(3, OUTPUT); // speed
  pinMode(5, OUTPUT); // right wheels on/off
  pinMode(6, OUTPUT); // left wheels on/off
  pinMode(7, OUTPUT); // right wheels direction 
  pinMode(8, OUTPUT); // left wheels direction 
  pinMode(A0, INPUT); // RIGHT SENSOR
  pinMode(A1, INPUT); // CENTRAL SENSOR
  pinMode(A2, INPUT); // LEFT SENSOR
}

void loop() {

  int R = analogRead(A0);
  int C = analogRead(A1);
  int L = analogRead(A2);

  //analogWrite(3, 0); // set initial speed to zero

  ////////////////////////////////////////////////////////////////////////

  if ((L>400) && (C>400) && (R>400)) { // TTT - turns right by convention
    Serial.println("ALL SENSORS ACTIVATED!");
    analogWrite(3, 150);
    analogWrite(5, 75); 
    digitalWrite(7, LOW); // turn right wheel backward
    analogWrite(6, 150); 
    digitalWrite(8, HIGH); //turn left wheel forward


    }
  ////////////////////////////////////////////////////
  else if ((R>400) && (C>400) && (L<= 400)) { // TTF - turns right
    Serial.println("line on R and C"); 
    analogWrite(3, 150);
    analogWrite(5, 75); 
    digitalWrite(7, LOW); // turn right wheel backward
    analogWrite(6, 150); //were testing this out will explain in person
    digitalWrite(8, HIGH); //turn left wheel forward

    }
  
  else if ((R>400) && (C<=400) && (L<= 400)) { // TFF - turns right more
    Serial.println("line on R"); 
    delay(2);
    analogWrite(3, 150);
    analogWrite(5, 75); 
    digitalWrite(7, LOW); // turn right wheel backward
    analogWrite(6, 150); //were testing this out will explain in person
    digitalWrite(8, HIGH); //turn left wheel forward
  
    }

  ////////////////////////////////////////////////////

  else if ((R<=400) && (C<=400) && (L>400)) { // FFT - turns left
    Serial.println("line on L"); //prints to terminal
    analogWrite(3, 150);
    analogWrite(5, 150); 
    digitalWrite(7, HIGH); // turn right wheel forward
    analogWrite(6, 75); 
    digitalWrite(8, LOW); //turn left wheel backward

    }

  else if ((R<=400) && (C>400) && (L>400)) { // FTT - turns left even more:
    Serial.println("line on L and C"); //prints to terminal
    delay(2);
    analogWrite(3, 150);
    analogWrite(5, 150); 
    digitalWrite(7, HIGH); // turn right wheel forward
    analogWrite(6, 75); 
    digitalWrite(8, LOW); //turn left wheel backward
 
    }
  
  /////////////////////////////////////////////////////////////////////////////////
  else if ((R<=400) && (C>400) && (L<=400)) { // FTF - go straight
    Serial.println("go straight");
    analogWrite(3, 125); //speed
    analogWrite(5, 125); 
    digitalWrite(7, HIGH); // turn right wheel forward
    analogWrite(6, 125); 
    digitalWrite(8, HIGH); //turn left wheel forward
    //delay(3);
    }

  //////////////////////////////////////////////////////////////////////////////

  else if ((R<=400) && (C<=400) && (L<=400)) { // FFF
    Serial.println("no line");
    
  }

  

}
