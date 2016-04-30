// Define the pins that power the motors.
const int Motor2Pin1 = 5;
const int Motor2Pin2 = 6;
const int Motor1Pin1 = 9;
const int Motor1Pin2 = 10;

// Define the pins for the limit switches
const int Switch1Pin = 8;

//variable for switch state
//int switch1State = 0;

// Initialize timer variables
boolean motors_on = false;
long sandingDuration = 30 * 1000; //seconds * conversion to milliseconds
long timeGoal = 0;
int test_read = 1;
long motor_delay = .5 * 1000; //seconds * conversion to milliseconds

//setup program
void setup() {
  Serial.begin(9600); //start serial so prinitng can occur
  Serial.println();
  initializeMotors(); //initialize all motors
  initializeSwitches(); //initialize all sensors
}

//main program loop
void loop() {
  //read state of switch
  /*
  //delay(500);
  //digitalRead(Switch1Pin);
  //Serial.println(switch1State);
  //check to see if the ball has hit the limit switch
  //if (Switch1Pin == 1) 
  */

  //test_read = Serial.read();
  if (test_read == 1){
    //set time to turn off motors
    timeGoal = sandingDuration + millis();
    //turn on motors
    startMotors();
  }

  //check to see if the motors have been on for the time goal
  if (motors_on && timeGoal <= millis()) {
    //turn off motors
    stopMotors();
  }
}

//initialization functions
//initializes all motors
void initializeMotors() {
  //motor 1
  pinMode(Motor1Pin1, OUTPUT);
  pinMode(Motor1Pin2, OUTPUT);
  //motor 2
  pinMode(Motor2Pin1, OUTPUT);
  pinMode(Motor2Pin2, OUTPUT);
  Serial.println("motors");
}

//initializes all sensors
void initializeSwitches() {
  //switch 1 - limit switch
  pinMode(Switch1Pin, INPUT);
  Serial.println("switches");
}

//motor control functions
//start all motors
void startMotors() {
  //print motors on
  Serial.println("Motors ON");
  //keep track of motors being on
  motors_on = true;
  //motor 1
  digitalWrite(Motor1Pin1, HIGH);
  //digitalWrite(Motor1Pin2, HIGH);
  //wait for motor 1 to start
  delay(500);
  //motor 2
  digitalWrite(Motor2Pin1, HIGH);
  //digitalWrite(Motor2Pin2, HIGH);
  test_read=0;
}

//stop all motors
void stopMotors() {
  //print motors off
  Serial.println("Motors OFF");
  //keep track of motors being off
  motors_on = false;
  //motor 1
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, LOW);
  //motor 2
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, LOW);
  test_read=0;
}

//conversion functions
//conters seconds to milliseconds
//int sec2Milli(double seconds) {
//  int milliseconds = seconds * 1000;
//
//  return milliseconds;
//}

