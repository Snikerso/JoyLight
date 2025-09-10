#ifndef JOYSTICK_H
#define JOYSTICK_H

// Joystick pin configuration
#define PIN_VRX A0
#define PIN_VRY A1
#define PIN_SW  2

struct JoystickValues {
    int valueX;
    int valueY;
    int valueButton;
  };
  
// Joystick variables
extern int cx; // kalibracja środka
extern JoystickValues values;

// Function declarations
void initJoystick();
JoystickValues readJoystickValues();
void calibrateCenter();

#endif
