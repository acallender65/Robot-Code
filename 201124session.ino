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
  int RS = map(R, sensorMin, sensorMax, 0,1);
  int C = analogRead(A1);
  int CS = map(C, sensorMin, sensorMax, 0,1);
  int L = analogRead(A2);
  int LS = map(L, sensorMin, sensorMax, 0,1);

  ////////////////////////////////////////////////////////////////////////

  //CASE FOR TTT - turns right by convention:
  if ((RS != 0) && (CS != 0) && (LS != 0)) {
    Serial.println("line on r, c, l"); //prints to terminal
    LineR = true;
    LineC = true;
    LineL = true;
    analogWrite(3, 250); //speed 
    analogWrite(5, 250); // turn right wheel - this is a convention
    }
  /////////////////////////////////////////////////////////////////////////////////

  //CASE FOR TTF - turns right:
  else if ((RS == 0) && (CS != 0) && (LS !=0)) {
    Serial.println("no line on r, line on c, line on l");
    LineR = false;
    LineC = true;
    LineL = true;
    analogWrite(3,250);
    analogWrite(5, 250);   
  }
  /////////////////////////////////////////////////////////////////////////////////

  //CASE FOR TFT - turns right by convention:
  else if ((RS == 0) && (CS != 0) && (LS !=0)){
    Serial.println("line on r, no line on c, line on l");
    LineR = true;
    LineC = false;
    LineL = true;
    analogWrite(3,250);
    analogWrite(5, 250);   
  }

  ////////////////////////////////////////////////////////////////////////

  //CASE FOR TFF - turns right even more:
  else if ((RS != 0) && (CS == 0) && (LS == 0)) {
    Serial.println("line on r"); //prints to terminal
    LineR = true;
    LineC = false;
    LineL = false;
    analogWrite(3, 250); //speed 
    analogWrite(5, 250); // turn right wheel
    }

  ////////////////////////////////////////////////////////////////////////

  //CASE FTT - turns left:
  else if ((RS != 0) && (CS != 0) && (LS == 0)){
    Serial.println("line on r, line on c, no line on l");
    LineR = true;
    LineC = true;
    LineL = false;
    analogWrite(3, 250);
    analogWrite(6,250);
  }  

  //ftf
  /////////////////////////////////////////////////////////////////////////////////

  //CASE FOR FTF - keeps going straight:
  else if ((RS == 0) && (CS != 0) && (LS == 0)) {
    Serial.println("no line on r, line on c, no line on l");
    LineR = false;
    LineC = true;
    LineL = false;
    analogWrite(3, 250); //speed 
    analogWrite(5, 250); // right wheels
    analogWrite(6, 250); // left wheels
  }

  //CASE FOR FFT - turns left even more:
  else if ((RS == 0) && (CS == 0) && (LS != 0)) {
    Serial.println("line on l"); //prints to terminal
    LineR = false;
    LineC = false;
    LineL = true;
    analogWrite(3, 250); //speed 
    analogWrite(6, 250); // turn left wheel
    }
  //CASE FOR FFF - runs in timed left n right:
  else if ((RS == 0) && (CS == 0) && (LS == 0)) {
    Serial.println("no line detected"); // prints to terminal
    LineR = false;
    LineC= false;
    LineL = false;
    analogWrite(3, HIGH);
    analogWrite(5, HIGH);
    analogWrite(6, HIGH);
    delay(50);
    analogWrite(6, HIGH);
    delay(50);
    analogWrite(3, HIGH);
    delay(50);
  }
}
