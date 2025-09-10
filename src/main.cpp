#include <Arduino.h>
#include "Display.h"
#include "Joystick.h"
#include "StepperMotor.h"

void setup() {
  Serial.begin(9600);
  Serial.println(F("Starting JoyLight system..."));
  
  // 1. Initialize joystick
  initJoystick();
  // 2. Initialize display
  initDisplay();
  // 3. Initialize stepper motor
  initStepperMotor();
  
  // 4. Show welcome message
  clearDisplay();
  showText("JoyLight", 0, 0, 2);
  showText("System Ready", 0, 20);
  updateDisplay();
  delay(2000);

}

void loop() {
  // 1. Read joystick values
  JoystickValues joystickValues = readJoystickValues();
  
  // 2. Control stepper motor with joystick X-axis
  continuousMotorControlWithJoystick(joystickValues.valueX, joystickValues.valueX);
  
  // 3. Display joystick values and motor status
  int direction = getJoystickDirection(joystickValues.valueX);
  float speed = getJoystickSpeed(joystickValues.valueX);
  clearDisplay();
  showText("Joystick Control", 0, 0, 1);
  showValue("Direction", direction, 0, 15);
  showValue("Speed", speed, 0, 25);
  
  // 4. Show motor direction and speed info
  
  if (direction == 0) {
    showText("Motor: STOP", 0, 45);
  } else if (direction == 1) {
    showText("Motor: CW", 0, 45);
  } else if (direction == -1) {
    showText("Motor: CCW", 0, 45);
  } else {
    showText("Motor: ERROR", 0, 45);
  }
  
  updateDisplay();

}