#include <Arduino.h>
#include "Display.h"
#include "Joystick.h"
#include "StepperMotor.h"

void setup() {
  Serial.begin(9600);
  Serial.println(F("Starting JoyLight system..."));
  
  // Initialize joystick
  initJoystick();
  
  // Initialize display
  initDisplay();
  
  // Initialize stepper motor
  initStepperMotor();
  
  // Show welcome message
  clearDisplay();
  showText("JoyLight", 0, 0, 2);
  showText("System Ready", 0, 20);
  updateDisplay();
  delay(2000);

}

void loop() {
  // Run the simple motor test with slower speed
  simpleMotorTest();
}