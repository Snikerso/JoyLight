#include "StepperMotor.h"

// Create AccelStepper object for TB6560 driver (Driver mode)
AccelStepper stepper(AccelStepper::DRIVER, PIN_STEP, PIN_DIR);

void initStepperMotor() {
  // Configure enable pin as output
  pinMode(PIN_ENA, OUTPUT);
  
  // Configure potentiometer pin as input
  pinMode(PIN_POT, INPUT);
  
  // Initialize stepper motor settings
  stepper.setMaxSpeed(MAX_SPEED);
  stepper.setAcceleration(ACCELERATION);
  stepper.setCurrentPosition(0);
  
  // Disable motor initially
  disableStepperMotor();
  
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

// Potentiometer direction control functions implementation
int readPotentiometerDirection() {
  int potValue = analogRead(PIN_POT);
  
  // Create dead zone in the middle (around 512)
  if (potValue > 450 && potValue < 574) {
    return 0; // Stop - middle position
  } else if (potValue <= 450) {
    return -1; // Counter-clockwise - left side
  } else {
    return 1; // Clockwise - right side
  }
}

float readPotentiometerSpeed() {
  int potValue = analogRead(PIN_POT);
  
  // Map potentiometer value to speed (0 to MAX_SPEED)
  float speed = map(potValue, 0, 1023, 0, MAX_SPEED);
  return speed;
}

void continuousMotorControlWithPotentiometer(int potDirection) {
  if (potDirection == 0) {
    // Stop motor
    stepper.stop();
    disableStepperMotor();
    return;
  }
  
  // Enable motor
  enableStepperMotor();
  
  // Set speed based on potentiometer
  float speed = readPotentiometerSpeed();
  stepper.setMaxSpeed(speed);
  
  // Set direction and move
  if (potDirection > 0) {
    stepper.move(1000); // Move forward
  } else {
    stepper.move(-1000); // Move backward
  }
  
  // Run one step
  stepper.run();
}


// Simple test function using AccelStepper
void simpleMotorTest() {
  Serial.println(F("=== ACCELSTEPPER MOTOR TEST ==="));
  
  // Enable motor
  enableStepperMotor();
  
  // Set conservative speed and acceleration for 6V motor
  stepper.setMaxSpeed(200);
  stepper.setAcceleration(100);
  
  // Move 20 steps forward
  Serial.println(F("Moving 20 steps forward..."));
  stepper.moveTo(20);
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  
  delay(2000);
  
  // Move back to position 0
  Serial.println(F("Moving back to position 0..."));
  stepper.moveTo(0);
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  
  disableStepperMotor();
  Serial.println(F("Test complete"));
  
  // Wait 5 seconds before next test
  delay(5000);
}
