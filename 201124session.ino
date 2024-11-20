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

// we are setting the min and max that the sensors will input
const int sensorMin = 0;
const int sensorMax = 255;

// declaring variables
bool LineR;
bool LineC;
bool LineL;

void loop() {

  int R = analogRead(A0);

  int C = analogRead(A1);

  int L = analogRead(A2);


  analogWrite(3, 0);

  ////////////////////////////////////////////////////////////////////////

  //CASE FOR TTT - turns right by convention:
  if ((R >400)) {
    
    Serial.println("LINE"); //prints to terminal

    analogWrite(3, 125); //speed
    analogWrite(5, 125); // turn right wheel - this is a convention
    digitalWrite(7, HIGH);
    analogWrite(6, 125); //turn left wheel backwards
    digitalWrite(8, LOW);
    }
  /////////////////////////////////////////////////////////////////////////////////
  else if (R<=400) {
    Serial.println("no line JFDHKJDFHSDJFJDSH"); //prints to terminal
    LineR = true;
    LineC = true;
    LineL = true;
    analogWrite(3, 0); //speed
    analogWrite(5, 0); // turn right wheel - this is a convention
    analogWrite(6, 0); //turn left wheel FORWARDS
    }

}
