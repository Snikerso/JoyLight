# Okablowanie Silnika Krokowego z Sterownikiem TB6560

## Konfiguracja Podstawowa

Połącz sterownik TB6560 z Arduino Uno:

| Sterownik TB6560 | Arduino Uno | Opis                  |
| ---------------- | ----------- | --------------------- |
| CLK+             | Pin 3       | Sygnał kroków (PWM)   |
| CLK-             | GND         | Masa sygnału kroków   |
| CW+              | Pin 4       | Kierunek obrotów      |
| CW-              | GND         | Masa sygnału kierunku |
| ENA+             | Pin 5       | Włączenie sterownika  |
| ENA-             | GND         | Masa włączenia        |
| VCC              | 5V          | Zasilanie logiki      |
| GND              | GND         | Masa                  |

## Zasilanie Silnika

| Sterownik TB6560 | Zasilanie | Opis                   |
| ---------------- | --------- | ---------------------- |
| VM+              | 12V-24V   | Zasilanie silnika      |
| VM-              | GND       | Masa zasilania silnika |

**WAŻNE**: VM- musi być połączony z tą samą masą (GND) co sterownik!

## Oznaczenia Pinów

Różne wersje sterownika TB6560 mogą mieć różne oznaczenia pinów:

| Funkcja   | Oznaczenie 1 | Oznaczenie 2 | Opis                 |
| --------- | ------------ | ------------ | -------------------- |
| Kroki     | PUL+ / PUL-  | CLK+ / CLK-  | Sygnał kroków        |
| Kierunek  | DIR+ / DIR-  | CW+ / CW-    | Kierunek obrotów     |
| Włączenie | ENA+ / ENA-  | ENA+ / ENA-  | Włączenie sterownika |

## Szczegóły Połączeń

### Połączenia sterowania:

- **CLK+** → **Pin 3** - Sygnał kroków (impulsy PWM)
- **CLK-** → **GND** - Masa sygnału kroków
- **CW+** → **Pin 4** - Kierunek obrotów (HIGH/LOW)
- **CW-** → **GND** - Masa sygnału kierunku
- **ENA+** → **Pin 5** - Włączenie sterownika (HIGH=włączony)
- **ENA-** → **GND** - Masa włączenia

### Połączenia zasilania:

- **VCC** → **5V** - Zasilanie logiki sterownika
- **GND** → **GND** - Masa (wspólna dla całego układu)
- **VM+** → **12V-24V** - Zasilanie silnika (osobne źródło)
- **VM-** → **GND** - Masa zasilania silnika (TA SAMA co GND sterownika!)

### Połączenia silnika:

- **A+** → **Czerwony przewód** silnika
- **A-** → **Niebieski przewód** silnika
- **B+** → **Zielony przewód** silnika
- **B-** → **Czarny przewód** silnika

## Konfiguracja w Kodzie

Przykładowa konfiguracja w `include/StepperMotor.h`:

```cpp
#define PIN_STEP 3    // Sygnał kroków (CLK)
#define PIN_DIR  4    // Kierunek (CW)
#define PIN_ENA  5    // Włączenie
#define STEPS_PER_REV 200  // Kroki na obrót (dla silnika 1.8°)
```

## Ustawienia Sterownika TB6560

### Mikroprzełączniki na sterowniku:

| Mikroprzełącznik | Pozycja | Opis                |
| ---------------- | ------- | ------------------- |
| SW1              | ON      | Pełny krok (1.8°)   |
| SW2              | OFF     | Pełny krok (1.8°)   |
| SW3              | OFF     | Pełny krok (1.8°)   |
| SW4              | ON      | Prąd silnika (1.5A) |
| SW5              | OFF     | Prąd silnika (1.5A) |
| SW6              | OFF     | Prąd silnika (1.5A) |

### Alternatywne ustawienia (mikrokroki):

- **1/2 kroku**: SW1=OFF, SW2=ON, SW3=OFF
- **1/4 kroku**: SW1=ON, SW2=ON, SW3=OFF
- **1/8 kroku**: SW1=OFF, SW2=OFF, SW3=ON

## Testowanie

1. Wgraj kod
2. Otwórz Monitor Serial (9600 baud)
3. Sprawdź komunikaty o inicjalizacji silnika
4. Silnik powinien wykonać testowy ruch

## Uwagi:

1. **Zasilanie**: Użyj osobnego zasilacza 12V-24V dla silnika
2. **Masa**: VM- i GND muszą być połączone (wspólna masa!)
3. **Prąd**: Dostosuj prąd silnika za pomocą mikroprzełączników
4. **Chłodzenie**: Sterownik może się grzać - zapewnij wentylację
5. **Izolacja**: Zasilanie silnika musi być odizolowane od logiki
6. **Kroki**: Domyślnie 200 kroków/obrót dla silnika 1.8°

## Bezpieczeństwo:

1. **Zawsze wyłącz zasilanie** przed podłączaniem/odłączaniem
2. **Sprawdź polaryzację** przewodów silnika
3. **Nie dotykaj** sterownika podczas pracy
4. **Użyj odpowiedniego zasilacza** z zabezpieczeniem przeciążeniowym

## Rozwiązywanie Problemów:

### Silnik nie obraca się:

- Sprawdź połączenia CLK+, CLK-, CW+, CW-
- Sprawdź czy ENA+ jest podłączony do HIGH
- Sprawdź zasilanie VM+ i VM-
- **Sprawdź czy VM- jest połączony z GND** (wspólna masa!)

### Silnik wibruje:

- Zmniejsz częstotliwość kroków
- Sprawdź ustawienia mikroprzełączników
- Dostosuj prąd silnika

### Sterownik się grzeje:

- Sprawdź czy prąd nie jest ustawiony za wysoko
- Zapewnij wentylację
- Sprawdź obciążenie silnika
