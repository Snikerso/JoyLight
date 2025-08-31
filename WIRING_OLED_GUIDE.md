# Okablowanie Wyświetlacza Waveshare 10451 OLED 1.3" 128x64px

## Konfiguracja SPI (domyślna)

Połącz wyświetlacz z Arduino Uno:

| Wyświetlacz | Arduino Uno | Opis         |
| ----------- | ----------- | ------------ |
| VCC         | 3.3V        | Zasilanie    |
| GND         | GND         | Masa         |
| DIN (MOSI)  | Pin 11      | Dane SPI     |
| CLK         | Pin 13      | Zegar SPI    |
| DC          | Pin 9       | Data/Command |
| CS          | Pin 10      | Chip Select  |
| RST         | Pin 8       | Reset        |

## Konfiguracja I2C (alternatywna)

Aby przełączyć na I2C, zmień w `src/Display.cpp`:

```cpp
#define USE_SPI 0  // Zmień z 1 na 0
```

Połączenia I2C:
| Wyświetlacz | Arduino Uno | Opis |
|-------------|-------------|------|
| VCC | 3.3V | Zasilanie |
| GND | GND | Masa |
| SDA | Pin A4 | Dane I2C |
| SCL | Pin A5 | Zegar I2C |

## Uwagi:

1. **Zasilanie**: Użyj 3.3V, nie 5V!
2. **Piny SPI**: Upewnij się, że piny 11, 13, 9, 10, 8 są wolne
3. **Piny I2C**: A4 i A5 są dedykowane dla I2C na Arduino Uno
4. **Reset**: Jeśli nie masz pinu reset, użyj -1 w konfiguracji I2C

## Testowanie:

1. Wgraj kod
2. Otwórz Monitor Serial (9600 baud)
3. Sprawdź komunikaty o inicjalizacji
4. Wyświetlacz powinien pokazać ramkę, potem tekst
