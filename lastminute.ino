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
    Serial.println("go straight TTT");
    
    analogWrite(3, 250); //speed
    analogWrite(5, 250); 
    digitalWrite(7, HIGH); // turn right wheel forward
    analogWrite(6, 250); 
    digitalWrite(8, HIGH); //turn left wheel forward
    //delay(3);
    delay(2);
    }
  ////////////////////////////////////////////////////
  else if ((R>400) && (C>400) && (L<= 400)) { // TTF - turns right
    Serial.println("line on R and C"); 
    analogWrite(3, 250);
    analogWrite(5, 100); 
    digitalWrite(7, LOW); // turn right wheel backward
    analogWrite(6, 250); //were testing this out will explain in person
    digitalWrite(8, HIGH); //turn left wheel forward

    }
  
  else if ((R>400) && (C<=400) && (L<= 400)) { // TFF - turns right more
    Serial.println("line on R"); 
    //delay(1.5);
    analogWrite(3, 250);
    analogWrite(5, 40); 
    digitalWrite(7, LOW); // turn right wheel backward
    analogWrite(6, 250); //were testing this out will explain in person
    digitalWrite(8, HIGH); //turn left wheel forward
  
    }

  ////////////////////////////////////////////////////

  else if ((R<=400) && (C<=400) && (L>400)) { // FFT - turns left
    Serial.println("line on L"); //prints to terminal
    analogWrite(3, 250);
    analogWrite(5, 250); 
    digitalWrite(7, HIGH); // turn right wheel forward
    analogWrite(6, 50); 
    digitalWrite(8, LOW); //turn left wheel backward

    }

  else if ((R<=400) && (C>400) && (L>400)) { // FTT - turns left even more:
    
    Serial.println("line on L and C"); //prints to terminal
    //delay(1.5);
    analogWrite(3, 250);
    analogWrite(5, 250); 
    digitalWrite(7, HIGH); // turn right wheel forward
    analogWrite(6, 40); 
    digitalWrite(8, LOW); //turn left wheel backward
    }
  
  /////////////////////////////////////////////////////////////////////////////////
  else if ((R<=400) && (C>400) && (L<=400)) { // FTF - go straight
    Serial.println("go straight");
    
    analogWrite(3, 250); //speed
    analogWrite(5, 250); 
    digitalWrite(7, HIGH); // turn right wheel forward
    analogWrite(6, 250); 
    digitalWrite(8, HIGH); //turn left wheel forward
    //delay(3);
    delay(2);
    }

  //////////////////////////////////////////////////////////////////////////////

  else if ((R<=400) && (C<=400) && (L<=400)) { // FFF
    Serial.println("no line");

    analogWrite(3, 250); //speed
    analogWrite(5, 250); 
    digitalWrite(7, HIGH); // turn right wheel forward
    analogWrite(6, 250); 
    digitalWrite(8, HIGH); //turn left wheel forward
    //delay(3);
    delay(20);
    

    //
    analogWrite(3, 250);
    analogWrite(5, 100); 
    digitalWrite(7, LOW); // turn right wheel backward
    analogWrite(6, 250); 
    digitalWrite(8, LOW); //turn left wheel forward

  }

}
