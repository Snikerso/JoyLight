#ifndef JOYSTICK_H
#define JOYSTICK_H

// Joystick pin configuration
#define PIN_VRX A3

// Joystick variables
extern int cx; // kalibracja środka
extern int odczyt;

// Function declarations
void initJoystick();
int readAxis();
void calibrateCenter();
int getJoystickValue();

#endif
