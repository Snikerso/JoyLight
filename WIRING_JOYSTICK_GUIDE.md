# Okablowanie Joysticka Analogowego - Adafruit 5628

## Konfiguracja Podstawowa

Połącz joystick analogowy z Arduino Uno:

| Joystick  | Arduino Uno | Opis                        |
| --------- | ----------- | --------------------------- |
| VCC       | 5V          | Zasilanie                   |
| GND       | GND         | Masa                        |
| VRX (AD2) | Pin A3      | Oś X (pozioma)              |
| GND       | GND         | Masa                        |
| SWITCH    | Pin A3      | Przycisk - opcjonalny       |
| VRY (AD1) | Nie używany | Oś Y (pionowa) - opcjonalna |

## Szczegóły Połączeń

### Wymagane połączenia:

- **VCC** → **5V** - Zasilanie joysticka
- **GND** → **GND** - Masa
- **VRX** → **Pin A3** - Odczyt pozycji poziomej

### Opcjonalne połączenia (dla rozszerzenia):

- **VRY** → **Pin A2** - Odczyt pozycji pionowej (wymaga modyfikacji kodu)
- **SW** → **Pin 2** - Przycisk joysticka (wymaga modyfikacji kodu)

## Konfiguracja w Kodzie

Aktualna konfiguracja w `include/Joystick.h`:

```cpp
#define PIN_VRX A3
```

## Kalibracja

Joystick automatycznie kalibruje środek przy starcie:

1. Upewnij się, że joystick jest w pozycji neutralnej
2. System pobiera 10 odczytów i oblicza średnią jako środek
3. Kalibracja trwa około 100ms

## Testowanie

1. Wgraj kod
2. Otwórz Monitor Serial (9600 baud)
3. Sprawdź komunikaty o inicjalizacji joysticka
4. Ruch joystickiem powinien zmieniać wartości w zakresie 0-1023

## Uwagi:

1. **Zasilanie**: Joystick wymaga 5V (nie 3.3V jak OLED)
2. **Pin analogowy**: Upewnij się, że pin A3 jest wolny
3. **Kalibracja**: Joystick musi być w pozycji neutralnej podczas startu
4. **Zakres**: Wartości analogowe 0-1023 (10-bit ADC)
5. **Szum**: Możliwe są niewielkie wahania w odczytach

## Rozszerzenie Funkcjonalności

Aby dodać obsługę osi Y i przycisku, zmodyfikuj `include/Joystick.h`:

```cpp
#define PIN_VRX A3
#define PIN_VRY A2  // Dodaj oś Y
#define PIN_SW  2   // Dodaj przycisk
```

I odpowiednio zmodyfikuj `src/Joystick.cpp`.
