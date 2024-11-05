// IDEA: we could define pins as macros at the top
// IDEA: we should experiment with analog/digital write/read
// IDEA: what is the max voltage? what do HIGH/LOW stand for?

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
bool lineR;
bool lineC;
bool lineL;

void loop() {
  // e.g. R stores the value of the value that A0 (right sensor) is sensing
  // if R = 0, then the right sensor has not sensed a line
  int R = analogRead(A0);
  
  // maps R (range 0-255) onto RS (range 0-1)
  int RS = map(R, sensorMin, sensorMax, 0,1);
  
  if (RS == 0) { // if right sensor doesn't sense a line
    Serial.println("no line on r"); // print to terminal
    lineR = false; // sets value of lineR (we'll use this variable later when considering the different situations)
    digitalWrite(5, LOW); // turn the speed off
    digitalWrite(3, LOW); // turn right wheels off
  }
  else { // i.e. if R != 0, if the right sensor does sense a line
    Serial.println("line on r");
    lineR = true;
    digitalWrite(5, 1); // turn the speed to 1
    digitalWrite(3, 1); // turn right wheels on
  }


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
    lineL = false;
  }
  else {
    Serial.println("line on l");
    lineL = true;
  }
}
