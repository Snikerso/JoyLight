# Okablowanie Taśmy LED WS2812B RGB

## Konfiguracja Podstawowa

Połącz taśmę LED WS2812B z Arduino Uno:

| Taśma LED WS2812B | Arduino Uno | Opis            |
| ----------------- | ----------- | --------------- |
| VCC (5V)          | 5V          | Zasilanie taśmy |
| GND               | GND         | Masa            |
| DIN (Data In)     | Pin 6       | Sygnał danych   |

## Szczegóły Połączeń

### Wymagane połączenia:

- **VCC (5V)** → **5V** - Zasilanie taśmy LED
- **GND** → **GND** - Masa
- **DIN (Data In)** → **Pin 6** - Sygnał danych WS2812B

### Opcjonalne połączenia:

- **DOUT (Data Out)** → **Następna taśma** - Łańcuchowanie taśm (jeśli masz więcej niż jedną)

## Konfiguracja w Kodzie

Aktualna konfiguracja w `include/LedStrip.h`:

```cpp
#define LED_PIN 6
#define NUM_LEDS 30  // Dostosuj do liczby diod w taśmie
```

## Zasilanie

### Ważne uwagi dotyczące zasilania:

1. **Prąd**: Każda dioda WS2812B może pobierać do 60mA przy pełnej jasności
2. **Zasilanie zewnętrzne**: Dla taśm dłuższych niż 8-10 diod użyj zewnętrznego zasilacza 5V
3. **Kondensator**: Dodaj kondensator 1000µF między VCC a GND dla stabilności
4. **Rezystor**: Dodaj rezystor 300-500Ω na linii danych dla lepszej jakości sygnału

### Schemat zewnętrznego zasilania:

```
Zewnętrzny zasilacz 5V
    ↓
    ├── VCC (taśma LED)
    ├── 5V (Arduino)
    └── GND (wspólna masa)
```

## Testowanie

1. Wgraj kod
2. Otwórz Monitor Serial (9600 baud)
3. Sprawdź komunikaty o inicjalizacji taśmy LED
4. Taśma powinna wyświetlić testowe kolory

## Uwagi:

1. **Zasilanie**: Taśma wymaga 5V (nie 3.3V)
2. **Prąd**: Sprawdź czy zasilacz może dostarczyć odpowiedni prąd
3. **Pin danych**: Upewnij się, że pin 6 jest wolny
4. **Długość taśmy**: Dostosuj `NUM_LEDS` do rzeczywistej liczby diod
5. **Biblioteka**: Użyj biblioteki FastLED lub NeoPixel

## Rozszerzenie Funkcjonalności

Aby dodać więcej taśm lub zmienić pin:

```cpp
#define LED_PIN 6
#define NUM_LEDS 30
#define BRIGHTNESS 128  // Jasność 0-255
```

## Bezpieczeństwo

1. **Zasilanie**: Zawsze używaj odpowiedniego zasilacza
2. **Przewody**: Użyj przewodów o odpowiednim przekroju
3. **Chłodzenie**: Długie taśmy mogą się nagrzewać
4. **Ochrona**: Dodaj bezpieczniki jeśli to konieczne

## Rozwiązywanie Problemów

### Taśma nie świeci:

- Sprawdź połączenia VCC, GND, DIN
- Sprawdź czy zasilacz dostarcza 5V
- Sprawdź czy pin danych jest poprawny

### Kolory są nieprawidłowe:

- Sprawdź kolejność RGB w kodzie
- Sprawdź czy biblioteka jest poprawnie zainstalowana

### Taśma miga lub resetuje się:

- Dodaj kondensator 1000µF
- Sprawdź czy zasilacz ma wystarczającą moc
- Skróć przewody danych
