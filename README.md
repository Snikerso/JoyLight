# JoyLight Project

Projekt Arduino z joystickiem i wyświetlaczem OLED.

## Struktura Projektu

### Pliki Główne

- `src/main.cpp` - Główny plik programu
- `platformio.ini` - Konfiguracja PlatformIO

### Moduły (Modularna Architektura)

#### Wyświetlacz OLED

- `include/Display.h` - Deklaracje funkcji wyświetlacza
- `src/Display.cpp` - Implementacja funkcji wyświetlacza

#### Joystick

- `include/Joystick.h` - Deklaracje funkcji joysticka
- `src/Joystick.cpp` - Implementacja funkcji joysticka

### Dokumentacja

- `WIRING_GUIDE.md` - Instrukcje okablowania wyświetlacza

## Funkcjonalności

### Wyświetlacz (Display.h/cpp)

- `initDisplay()` - Inicjalizacja wyświetlacza
- `clearDisplay()` - Czyszczenie ekranu
- `showText()` - Wyświetlanie tekstu
- `showValue()` - Wyświetlanie wartości z etykietą
- `updateDisplay()` - Aktualizacja wyświetlacza

### Joystick (Joystick.h/cpp)

- `initJoystick()` - Inicjalizacja joysticka
- `readAxis()` - Odczyt wartości osi
- `calibrateCenter()` - Kalibracja środka
- `getJoystickValue()` - Pobranie wartości joysticka

## Korzyści Modularnej Architektury

1. **Separacja odpowiedzialności** - Każdy moduł ma swoją funkcję
2. **Reużywalność** - Moduły można używać w innych projektach
3. **Łatwość utrzymania** - Zmiany w jednym module nie wpływają na inne
4. **Czytelność** - Główny plik jest prosty i zrozumiały
5. **Testowanie** - Każdy moduł można testować osobno

## Jak Dodać Nowy Moduł

1. Stwórz plik nagłówkowy `include/NowyModul.h`
2. Stwórz plik implementacji `src/NowyModul.cpp`
3. Dodaj `#include "NowyModul.h"` w `main.cpp`
4. Wywołaj funkcje inicjalizacji w `setup()`
