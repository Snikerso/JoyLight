#ifndef DISPLAY_H
#define DISPLAY_H

#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

// Display configuration
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Waveshare 10451 OLED 1.3" 128x64px Configuration
// SPI Configuration (dla Waveshare 10451)
#define OLED_MOSI   11  // DIN
#define OLED_CLK    13  // CLK
#define OLED_DC     9   // DC
#define OLED_CS     10  // CS
#define OLED_RESET  8   // RST

// I2C Configuration (alternatywa dla Waveshare 10451)
#define I2C_OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

// Display object
extern Adafruit_SH1106G display;

// Function declarations
void initDisplay();
void clearDisplay();
void showText(const char* text, int x = 0, int y = 0, int size = 1);
void showValue(const char* label, int value, int x = 0, int y = 0);
void updateDisplay();

#endif
