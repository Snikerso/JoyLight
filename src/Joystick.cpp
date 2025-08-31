#include "Joystick.h"
#include <Arduino.h>

// Joystick variables definition
int cx = 0; // kalibracja środka
int odczyt = 0;

void initJoystick() {
  pinMode(PIN_VRX, INPUT);
  Serial.println(F("Joystick initialized"));
  
  // Kalibracja środka
  calibrateCenter();
}

int readAxis() {
  odczyt = analogRead(PIN_VRX);
  return odczyt;
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

int getJoystickValue() {
  int value = readAxis();
  // Można dodać dodatkowe przetwarzanie tutaj
  return value;
}
