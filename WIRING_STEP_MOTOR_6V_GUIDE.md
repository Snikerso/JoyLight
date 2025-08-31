# Okablowanie Silnika Krokowego 6V z Sterownikiem TB6560

## ⚠️ WAŻNE - Silnik 6V

**UWAGA**: Silnik 6V wymaga specjalnej uwagi przy konfiguracji TB6560!

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

## Zasilanie Silnika 6V

| Sterownik TB6560 | Zasilanie | Opis                   |
| ---------------- | --------- | ---------------------- |
| VM+              | 6V        | Zasilanie silnika      |
| VM-              | GND       | Masa zasilania silnika |

**WAŻNE**:

- VM- musi być połączony z tą samą masą (GND) co sterownik!
- Użyj zasilacza 6V z odpowiednim prądem (zazwyczaj 1-2A)
- **NIE używaj 12V-24V** - może uszkodzić silnik 6V!

## Ustawienia Sterownika TB6560 dla 6V

### Mikroprzełączniki na sterowniku:

| Mikroprzełącznik | Pozycja | Opis                |
| ---------------- | ------- | ------------------- |
| SW1              | ON      | Pełny krok (1.8°)   |
| SW2              | OFF     | Pełny krok (1.8°)   |
| SW3              | OFF     | Pełny krok (1.8°)   |
| SW4              | OFF     | Prąd silnika (0.5A) |
| SW5              | OFF     | Prąd silnika (0.5A) |
| SW6              | OFF     | Prąd silnika (0.5A) |

**UWAGA**: Dla silnika 6V ustaw prąd na minimum (0.5A)!

### Alternatywne ustawienia prądu dla 6V:

- **0.5A**: SW4=OFF, SW5=OFF, SW6=OFF (zalecane)
- **1.0A**: SW4=ON, SW5=OFF, SW6=OFF (jeśli silnik wymaga)
- **1.5A**: SW4=OFF, SW5=ON, SW6=OFF (tylko jeśli konieczne)

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
- **VM+** → **6V** - Zasilanie silnika (osobne źródło 6V!)
- **VM-** → **GND** - Masa zasilania silnika (TA SAMA co GND sterownika!)

### Połączenia silnika:

- **A+** → **Czerwony przewód** silnika
- **A-** → **Niebieski przewód** silnika
- **B+** → **Zielony przewód** silnika
- **B-** → **Czarny przewód** silnika

## Konfiguracja w Kodzie

Konfiguracja w `include/StepperMotor.h`:

```cpp
#define PIN_STEP 3    // Sygnał kroków (CLK)
#define PIN_DIR  4    // Kierunek (CW)
#define PIN_ENA  5    // Włączenie
#define STEPS_PER_REV 200  // Kroki na obrót (dla silnika 1.8°)
#define DEFAULT_SPEED 500  // Wolniejsza prędkość dla 6V
```

## Testowanie Silnika 6V

1. **Sprawdź zasilanie**: Upewnij się, że używasz 6V, nie 12V!
2. **Sprawdź prąd**: Ustaw mikroprzełączniki na 0.5A
3. **Wgraj kod**: Użyj zaktualizowanego kodu dla 6V
4. **Monitor Serial**: Otwórz Monitor Serial (9600 baud)
5. **Obserwuj**: Silnik powinien poruszać się wolniej i płynniej

## Uwagi Specjalne dla 6V:

1. **Wolniejsza prędkość**: Silnik 6V wymaga wolniejszych kroków
2. **Niższy prąd**: Ustaw prąd na minimum (0.5A)
3. **Mniejsze obciążenie**: Nie przeciążaj silnika
4. **Dłuższe opóźnienia**: Więcej czasu między krokami
5. **Płynniejszy ruch**: Mniej wibracji przy niższym napięciu

## Bezpieczeństwo dla 6V:

1. **Zawsze wyłącz zasilanie** przed podłączaniem/odłączaniem
2. **Sprawdź napięcie** - używaj tylko 6V!
3. **Sprawdź polaryzację** przewodów silnika
4. **Nie dotykaj** sterownika podczas pracy
5. **Użyj odpowiedniego zasilacza** 6V z zabezpieczeniem

## Rozwiązywanie Problemów dla 6V:

### Silnik tylko "pyka" zamiast się obracać:

**To najczęstszy problem z silnikami 6V!**

#### 1. Sprawdź zasilanie:

- **Upewnij się, że używasz dokładnie 6V** (nie 5V, nie 7V!)
- Sprawdź czy zasilacz 6V ma odpowiedni prąd (1-2A)
- Zmierz napięcie multimetrem na VM+ i VM-

#### 2. Sprawdź ustawienia mikroprzełączników:

- **SW4=OFF, SW5=OFF, SW6=OFF** (prąd 0.5A)
- **SW1=ON, SW2=OFF, SW3=OFF** (pełny krok)

#### 3. Sprawdź połączenia:

- **VM- musi być połączony z GND** sterownika!
- Sprawdź wszystkie połączenia przewodów silnika
- Sprawdź czy CLK+, CW+, ENA+ są podłączone do pinów 3, 4, 5

#### 4. Sprawdź kod:

- Użyj bardzo wolnych prędkości (20-50 kroków/sekundę)
- Bardzo długie impulsy (10-100ms zamiast mikrosekund)
- Duże opóźnienia między krokami (1-2 sekundy)

#### 5. Dodatkowe sprawdzenia:

- **Sprawdź czy silnik nie jest mechanicznie zablokowany**
- **Sprawdź czy silnik nie jest uszkodzony** (spróbuj obrócić ręcznie)
- **Sprawdź czy wszystkie przewody są dobrze połączone**
- **Sprawdź czy nie ma zwarcia** między przewodami
- **Sprawdź czy sterownik nie jest uszkodzony** (LED na sterowniku)

### Silnik nie obraca się:

- Sprawdź czy używasz 6V (nie 12V!)
- Sprawdź połączenia CLK+, CLK-, CW+, CW-
- Sprawdź czy ENA+ jest podłączony do HIGH
- Sprawdź ustawienia prądu (0.5A)
- **Sprawdź czy VM- jest połączony z GND**

### Silnik wibruje mocno:

- Zmniejsz częstotliwość kroków w kodzie
- Sprawdź ustawienia mikroprzełączników
- Zmniejsz prąd silnika
- Sprawdź obciążenie

### Silnik się grzeje:

- Sprawdź czy prąd nie jest ustawiony za wysoko
- Zmniejsz prędkość w kodzie
- Sprawdź obciążenie silnika
- Zapewnij wentylację

### Ruch jest nieregularny:

- Zwiększ opóźnienia między krokami
- Sprawdź zasilanie 6V (stabilność)
- Sprawdź połączenia przewodów silnika
