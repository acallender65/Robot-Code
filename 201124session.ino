// IDEA: we could define pins as macros at the top
// IDEA: we should experiment with analog/digital write/read
// IDEA: what is the max voltage? what do HIGH/250 stand for?

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

  if ((R >400) && (C>400) && (L>400)) { //CASE FOR TTT - turns right by convention:
    Serial.println("ALL SENSORS ACTIVATED!"); //prints to terminal
    analogWrite(3, 125);
    analogWrite(5, 125); 
    digitalWrite(7, LOW); // turn right wheel backward
    analogWrite(6, 125); 
    digitalWrite(8, HIGH); //turn left wheel forward
    }
  /////////////////////////////////////////////////////////////////////////////////
  else if ((R<=400) {
    Serial.println("no line JFDHKJDFHSDJFJDSH"); //prints to terminal
    analogWrite(3, 0); //speed
    analogWrite(5, 0); // turn right wheel - this is a convention
    analogWrite(6, 0); //turn left wheel FORWARDS
    }

}
