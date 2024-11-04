void setup() {
// testcomment
  Serial.begin(9600);

  pinMode(3, OUTPUT); // speed
  pinMode(5, OUTPUT); // right wheels on/off
  pinMode(6, OUTPUT); // left wheels on/off
  pinMode(7, OUTPUT); // right wheels direction 
  pinMode(8, OUTPUT); // left wheels direction 
  pinMode(A0, INPUT); // RIGHT SENSOR
  pinMode(A1, INPUT); // CENTRAL SENSOR
  pinMode(A2, INPUT); // LEFT SENSOR
}

const int sensorMin = 0;
const int sensorMax = 255;
bool lineR;
bool lineC;
bool lineL;

void loop() {

  int R = analogRead(A0);
  int C = analogRead(A1);
  int L = analogRead(A2);

  int RS = map(R, sensorMin, sensorMax, 0,1);
  int CS = map(C, sensorMin, sensorMax, 0,1);
  int LS = map(L, sensorMin, sensorMax, 0,1);

  if (RS == 0) {
    Serial.println("no line on r");
    lineR = false;
    digitalWrite(5, LOW);
    digitalWrite(3, LOW);
  }
  else {
    Serial.println("line on r");
    lineR = true;
    digitalWrite(5, 1);
    digitalWrite(3, 1);
  }


   ///
  if (CS == 0) {
    Serial.println("no line on c");
    lineC = false;
  }
  else {
    Serial.println("line on c");
    lineC = true;
  }

   ///
  if (LS == 0) {
    Serial.println("no line on l ");
    lineL = false;
  }
  else {
    Serial.println("line on l");
    lineL = true;
  }

}
