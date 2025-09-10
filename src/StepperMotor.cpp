#include "StepperMotor.h"

// Create AccelStepper object for TB6560 driver (Driver mode)
AccelStepper stepper(AccelStepper::DRIVER, PIN_STEP, PIN_DIR);

void initStepperMotor() {
  // Configure enable pin as output
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_DIR, OUTPUT);
  pinMode(PIN_STEP, OUTPUT);

  // Configure potentiometer pin as input
  pinMode(PIN_POT, INPUT);
  
  // Initialize stepper motor settings
  stepper.setMaxSpeed(MAX_SPEED);
  stepper.setAcceleration(ACCELERATION);
  stepper.setCurrentPosition(0);
  
  // Disable motor initially
  enableStepperMotor();
  
  Serial.println(F("AccelStepper motor initialized"));
  Serial.print(F("Max speed: "));
  Serial.print(MAX_SPEED);
  Serial.println(F(" steps/sec"));
  Serial.print(F("Acceleration: "));
  Serial.print(ACCELERATION);
  Serial.println(F(" steps/sec²"));
  Serial.println(F("Potentiometer connected to A0"));
}

void enableStepperMotor() {
  digitalWrite(PIN_ENA, HIGH);
  Serial.println(F("Stepper motor enabled"));
}

void disableStepperMotor() {
  digitalWrite(PIN_ENA, LOW);
  Serial.println(F("Stepper motor disabled"));
}

void setDirection(bool clockwise) {
  // Direction is handled automatically by AccelStepper
  // This function is kept for compatibility
  Serial.println(clockwise ? F("Direction: Clockwise") : F("Direction: Counter-clockwise"));
}

void setSpeed(float speed) {
  stepper.setMaxSpeed(speed);
  Serial.print(F("Speed set to: "));
  Serial.print(speed);
  Serial.println(F(" steps/sec"));
}

void setAcceleration(float acceleration) {
  stepper.setAcceleration(acceleration);
  Serial.print(F("Acceleration set to: "));
  Serial.print(acceleration);
  Serial.println(F(" steps/sec²"));
}

void stepMotor(int steps) {
  if (steps == 0) return;
  
  enableStepperMotor();
  
  // Move relative to current position
  stepper.move(steps);
  
  // Run the motor until it reaches the target
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  
  disableStepperMotor();
}

void rotateDegrees(float degrees) {
  int steps = (int)(degrees * STEPS_PER_REV / 360.0);
  stepMotor(steps);
}

void rotateRevolutions(float revolutions) {
  int steps = (int)(revolutions * STEPS_PER_REV);
  stepMotor(steps);
}

void moveToPosition(long position) {
  enableStepperMotor();
  stepper.moveTo(position);
  
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  
  disableStepperMotor();
}

void moveRelative(long steps) {
  stepMotor(steps);
}

void runMotor() {
  stepper.run();
}

void stopMotor() {
  stepper.stop();
  disableStepperMotor();
}

// Joystick control functions implementation
int getJoystickDirection(int value) {
  // Create dead zone in the middle (around 512)
  // Using a wider dead zone for better control

  int leftMax = 300;  
  int rightMax = 400;

  if (value > leftMax && value < rightMax) {
    return 0; // Stop - middle position - stop
  } else if (value <= leftMax) {
    return -1; // Counter-clockwise - left side
  } else {
    return 1; // Clockwise - right side
  }
}

float getJoystickSpeed(int value) {
  // TODO ZROBIC ZEBY wartość od zera do srodka była 0-10, a od srodka do max była 10-0
  

  // int center = 412;
  // int distance = abs(value - center);
  // Map distance to speed (0 to MAX_SPEED)
  // Start from dead zone edge (112 from center) to max distance (512 from center)
  // Serial.print(F("Joystick value: "));
  // Serial.println(distance);

  // Mapuj odległość: 10-1023 → 0-10
  float speed = map(value, 10, 1023, 1, 10);

  Serial.print(F("Joystick speed: "));
  Serial.println(speed);
  
  // Ograniczenia prędkości
  // if (speed < 100) speed = 100;  // Minimum dla płynnego ruchu
  // if (speed > MAX_SPEED) speed = MAX_SPEED;
  
  return speed;
}

void continuousMotorControlWithJoystick(int joystickX, int joystickY) {
  int direction = getJoystickDirection(joystickX);
  float speed = getJoystickSpeed(joystickY);
  Serial.print(F("Joystick speed: "));
  Serial.println(speed);
  
  // set speed 
  if (direction == -1) {
    stepper.setSpeed(speed);
  } else if (direction == 1) {
    stepper.setSpeed(-speed);
  } else {
    stepper.stop();
    disableStepperMotor();
    return;
  }

  // run motor
  stepper.runSpeed();
}

void simpleMotorTest() {
  Serial.println(F("=== ACCELSTEPPER MOTOR TEST ==="));
  
  // Enable motor
  enableStepperMotor();
  
  // Set conservative speed and acceleration for 6V motor
  stepper.setMaxSpeed(1000);
  stepper.setSpeed(500);
  stepper.runSpeed();
}
