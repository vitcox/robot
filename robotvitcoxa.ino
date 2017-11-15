// define pins for the central echo sensor
#define trigPin 10
#define echoPin 11 

//left motor
#define enA 3 // MUST BE PWN pin
#define in1 4
#define in2 5

//right motor
#define enB 6 // must be PWN pin
#define in3 7
#define in4 8

int motorSpeedA = 0; // variable to control the speed of indyvidual wheel
int motorSpeedB = 0;
int vel = 255; // Speed of the robot

void setup(){ // Initializing variables
  Serial.begin(9600); // set up Serial library at 9600 bps

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)  

  //Initalization messages
  Serial.println(" Mr.robot");
  Serial.println(" Ready in 5 seconds!");

  //initial speed of the robot
  analogWrite(enA, 120);
  analogWrite(enB, 120);
  //turn off motors during set up or make sure they are off before we start
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(1000);
}


long GetDistance() {
  long duration, distance; // start the scan
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;// convert the distance to centimeters.
  return distance;
}


void motoF() {  // REVERSE Set Motor A backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B backward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }


void motoB() {  // FORWARD 
    //Set Motor A forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Set Motor B forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }

void motoL() {  // TURN LEFT 1 WHEEL 
  // Set Motor A forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // 2nd motor stop
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);}

void motoR() {  // TURN TIGHT 1 WHEEL
  // Spin motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // Set Motor B backward  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);}

void rotateL() {// Rotate robot using 2 wheels LEFT
    // Set Motor A backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);}

void rotateR() {// Rotate robot using 2 wheels RIGHT

    // Set Motor A forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Set Motor B backward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }

void loop() {
 // TODO try to delay the start, so the it does not start when conneting battery up
 long distance;
 
   distance = GetDistance();
   Serial.print(distance);

   if (distance < 30) //If we are too close to the obstacle  
          {
            Serial.println("Obstacle close");
            // here we put what we need when robot sees a wall
            motoB();
            delay(500);
            
            rotateR();
            // count time, if its going too long maybe change direction ? Or if distance is nieskonczony
            delay(500);
              
          }

  else //
          {
            Serial.println(" Clear way - FORWARD");
            
            motoF();
            delay(200); // wait for a second until next check
            
          } 
          
}
