#include "Display.h"


// Display object definition - SPI version dla Waveshare 10451
Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT,
  &SPI, OLED_DC, OLED_RESET, OLED_CS);

void initDisplay() {
  // Inicjalizacja SPI dla Waveshare 10451
  SPI.begin();
  Serial.println(F("Initializing SPI mode..."));
  
  // Próba inicjalizacji wyświetlacza SPI
  if(!display.begin(0x3C)) {
    Serial.println(F("SH110X SPI allocation failed"));
    Serial.println(F("Check SPI wiring"));
    for(;;); // Błąd - zatrzymaj
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0,0);
  display.println(F("Hello OLED!"));
  display.display();
}

void clearDisplay() {
  display.clearDisplay();
}

void showText(const char* text, int x, int y, int size) {
  display.setTextSize(size);
  display.setCursor(x, y);
  display.println(text);
}

void showValue(const char* label, int value, int x, int y) {
  display.setCursor(x, y);
  display.print(label);
  display.print(": ");
  display.println(value);
}

void updateDisplay() {
  display.display();
}

