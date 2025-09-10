#include "Joystick.h"
#include <Arduino.h>

// Joystick variables definition
int cx = 0; // kalibracja środka
int valueX = 0;
int valueY = 0;
int valueButton = 0;

void initJoystick() {
  pinMode(PIN_VRX, INPUT);
  Serial.println(F("Joystick initialized"));
  
  // Kalibracja środka
  calibrateCenter();
}


JoystickValues readJoystickValues() {
  valueX = analogRead(PIN_VRX);
  valueY = analogRead(PIN_VRY);
  valueButton = digitalRead(PIN_SW);


  return { valueX, valueY, valueButton };
}

void calibrateCenter() {
  // Pobierz kilka odczytów i oblicz średnią jako środek
  int sum = 0;
  for(int i = 0; i < 10; i++) {
    sum += analogRead(PIN_VRX);
    delay(10);
  }
  cx = sum / 10;
  
  Serial.print(F("Joystick center calibrated at: "));
  Serial.println(cx);
}

