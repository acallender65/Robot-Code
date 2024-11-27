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


  analogWrite(3, 0);

  ////////////////////////////////////////////////////////////////////////

  //CASE FOR TTT - turns right by convention:
  if ((R >400) && (C>400) && (L>400)) { 
    Serial.println("ALL SENSORS ACTIVATED!"); //prints to terminal
    analogWrite(3, 125);
    analogWrite(5, 125); 
    digitalWrite(7, LOW); // turn right wheel backward
    analogWrite(6, 188); //were testing this out will explain in person
    digitalWrite(8, HIGH); //turn left wheel forward
    }


 //CASE FOR TTF - turns right:
  if ((R >400) && (C>400) && (L <= 400)) { 
    Serial.println("line on R and C"); //prints to terminal
    analogWrite(3, 125);
    analogWrite(5, 125); 
    digitalWrite(7, LOW); // turn right wheel backward
    analogWrite(6, 125); //were testing this out will explain in person
    digitalWrite(8, HIGH); //turn left wheel forward
    }

  //CASE FOR TFF - turns right even more:
  if ((R >400) && (C <= 400) && (L<=400)) { 
    //Serial.println("line on R"); //prints to terminal
    //analogWrite(3, 125);
    //analogWrite(5, 125); 
    //digitalWrite(7, HIGH); // turn right wheel backward
    //analogWrite(6, 63); 
    //digitalWrite(8, HIGH); //turn left wheel forward

    analogWrite(3, 125);
    analogWrite(5, 125); 
    digitalWrite(7, LOW); // turn right wheel backward
    analogWrite(6, 125); 
    digitalWrite(8, HIGH); //turn left wheel forward
    }


  //CASE FOR FTT - turns left:
  if ((R <= 400) && (C>400) && (L>400)) { 
    Serial.println("line on C and L"); //prints to terminal
    analogWrite(3, 125);
    analogWrite(5, 188); 
    digitalWrite(7, HIGH); // turn right wheel backward
    analogWrite(6, 125); 
    digitalWrite(8, LOW); //turn left wheel forward
    }
  
  
  //CASE FOR FTF - keeps going straight:
  if ((R <= 400) && (C>400) && (L <= 400)) { 
    Serial.println("line on C"); //prints to terminal
    analogWrite(3, 125);
    analogWrite(5, 125); 
    digitalWrite(7, LOW); // turn right wheel backward
    analogWrite(6, 125); 
    digitalWrite(8, HIGH); //turn left wheel forward
    }
  
  
  //CASE FOR FFT - turns left even more:
  if ((R <= 400) && (C <= 400) && (L>400)) { 
    Serial.println("line on L"); //prints to terminal
    analogWrite(3, 125);
    analogWrite(5, 188); 
    digitalWrite(7, HIGH); // turn right wheel backward
    analogWrite(6, 125); 
    digitalWrite(8, LOW); //turn left wheel forward
    }
  
  
  //CASE FOR FFF - runs in timed left n right:
  if ((R <= 400) && (C <= 400) && (L <= 400)) { 
    Serial.println("no line"); //prints to terminal
    analogWrite(3, 125);
    analogWrite(5, 125);
    digitalWrite(7, HIGH);
    delay(50);
    analogWrite(6, 125);
    digitalWrite(8, HIGH);
    delay(50);
    }

  //CASE FOR TFT:
  if ((R >400) && (C <= 400) && (L>400)) { 
     Serial.println("no line"); //prints to terminal
    analogWrite(3, 125);
    analogWrite(5, 125);
    digitalWrite(7, HIGH);
    delay(50);
    analogWrite(6, 125);
    digitalWrite(8, HIGH);
    delay(50);
    }

}
