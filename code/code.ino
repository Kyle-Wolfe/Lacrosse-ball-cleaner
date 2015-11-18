// Define the pins that power the motors.
const int Motor1Pin1 = 5;
const int Motor1Pin2 = 6;
const int Motor2Pin1 = 9;
const int Motor2Pin2 = 10;

// Define the pins for the limit switches
const int Switch1Pin = 8;

// Initialize timer variables
boolean motors_on = false;
long sandingDuration = 600;
long timeGoal = 0;

void setup() {
  initializeMotors();
}

void loop() {
  if (Switch1Pin == 1) {
    motors_on = true;
    timeGoal = sandingDuration + millis();
    startMotors();
  }

  if (motors_on && timeGoal <= millis()) {
    motors_on = false;
    stopMotors();
  }
}

void initializeMotors() {
  pinMode(Motor1Pin1, OUTPUT);
  pinMode(Motor1Pin2, OUTPUT);
  pinMode(Motor2Pin1, OUTPUT);
  pinMode(Motor2Pin2, OUTPUT);
}

void initializeSwitches() {
  pinMode(Switch1Pin, INPUT);
}

void startMotors() {
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, HIGH);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, HIGH);
}

void stopMotors() {
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, LOW);
}
