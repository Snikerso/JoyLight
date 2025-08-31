#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

#include <Arduino.h>
#include <AccelStepper.h>

// Pin definitions for TB6560 stepper driver
#define PIN_STEP 3    // CLK+ - Step signal (PWM)
#define PIN_DIR  4    // CW+ - Direction signal
#define PIN_ENA  5    // ENA+ - Enable signal

// Potentiometer pin for speed control
#define PIN_POT A0    // Analog pin for potentiometer

// Stepper motor configuration
#define STEPS_PER_REV 200  // Steps per revolution (1.8° stepper)
#define MAX_SPEED 1000     // Maximum speed in steps per second
#define ACCELERATION 500   // Acceleration in steps per second squared

// Global AccelStepper object
extern AccelStepper stepper;

// Function declarations
void initStepperMotor();
void enableStepperMotor();
void disableStepperMotor();
void setDirection(bool clockwise);
void stepMotor(int steps);
void rotateDegrees(float degrees);
void rotateRevolutions(float revolutions);
void setSpeed(float speed);
void setAcceleration(float acceleration);
void runMotor();
void stopMotor();
void moveToPosition(long position);
void moveRelative(long steps);

// Potentiometer control functions
int readPotentiometerDirection();
void continuousMotorControlWithPotentiometer(int potDirection);
float readPotentiometerSpeed();

// Motor diagnostic functions
bool checkMotorResponse();
void testMotorPhases();
void testMotorCurrent();
void displayMotorStatus();
void simpleMotorTest();

#endif // STEPPER_MOTOR_H
