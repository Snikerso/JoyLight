# 🚨 SILNIK KROKOWY NIE DZIAŁA - PRZEWODNIK DIAGNOSTYCZNY

## 🔍 **KROK 1: Sprawdź połączenia elektryczne**

### Sprawdź zasilanie:

- ✅ **Zasilacz 6V** jest podłączony do VM+ i VM-
- ✅ **VM- jest połączony z GND** sterownika
- ✅ **VCC (5V)** jest podłączony do sterownika
- ✅ **GND** jest wspólny dla całego układu

### Sprawdź połączenia sterowania:

- ✅ **CLK+** → **Pin 3** Arduino
- ✅ **CLK-** → **GND**
- ✅ **CW+** → **Pin 4** Arduino
- ✅ **CW-** → **GND**
- ✅ **ENA+** → **Pin 5** Arduino
- ✅ **ENA-** → **GND**

### Sprawdź połączenia silnika:

- ✅ **A+** → **Czerwony** przewód silnika
- ✅ **A-** → **Niebieski** przewód silnika
- ✅ **B+** → **Zielony** przewód silnika
- ✅ **B-** → **Czarny** przewód silnika

## 🔧 **KROK 2: Sprawdź ustawienia sterownika TB6560**

### Mikroprzełączniki (dla silnika 6V):

```
SW1 = ON   (pełny krok)
SW2 = OFF  (pełny krok)
SW3 = OFF  (pełny krok)
SW4 = OFF  (prąd 0.5A)
SW5 = OFF  (prąd 0.5A)
SW6 = OFF  (prąd 0.5A)
```

## 📱 **KROK 3: Test programowy**

### 1. Wgraj kod i otwórz Monitor Szeregowy (9600 baud)

### 2. Obserwuj komunikaty:

```
Stepper motor initialized
Potentiometer connected to A0
=== Stepper Motor Test (6V) - SIMPLE DIAGNOSTIC ===
Test 1: Basic connectivity...
Stepper motor enabled
Stepper motor disabled
Test 2: Single step test...
Step 1
Step 2
...
```

### 3. Jeśli widzisz te komunikaty, ale silnik nie rusza:

- Problem jest w połączeniach elektrycznych
- Sprawdź ponownie wszystkie przewody

## 🔌 **KROK 4: Testy elektryczne z multimetrem**

### Sprawdź napięcia:

- **VM+ do VM-**: 6V
- **VCC do GND**: 5V
- **Pin 3 do GND**: 0V/5V (zmienia się)
- **Pin 4 do GND**: 0V/5V (zmienia się)
- **Pin 5 do GND**: 0V/5V (zmienia się)

### Sprawdź rezystancję uzwojeń silnika:

- **Czerwony do Niebieski**: 2-10 ohmów
- **Zielony do Czarny**: 2-10 ohmów
- **Czerwony do Zielony**: ∞ (brak połączenia)
- **Niebieski do Czarny**: ∞ (brak połączenia)

## 🚨 **KROK 5: Najczęstsze problemy**

### Problem 1: Silnik "pyka" ale nie obraca się

**Rozwiązanie:**

- Sprawdź czy używasz dokładnie 6V (nie 5V!)
- Zmniejsz prąd do 0.5A (SW4=OFF, SW5=OFF, SW6=OFF)
- Sprawdź czy VM- jest połączony z GND

### Problem 2: Silnik nie reaguje wcale

**Rozwiązanie:**

- Sprawdź połączenia CLK+, CW+, ENA+
- Sprawdź czy ENA+ jest podłączony do Pin 5
- Sprawdź czy wszystkie masy (GND) są połączone

### Problem 3: Silnik wibruje mocno

**Rozwiązanie:**

- Zmniejsz prędkość w kodzie
- Sprawdź ustawienia mikroprzełączników
- Sprawdź obciążenie silnika

### Problem 4: Sterownik się grzeje

**Rozwiązanie:**

- Sprawdź czy prąd nie jest ustawiony za wysoko
- Sprawdź połączenia silnika
- Sprawdź czy nie ma zwarcia

## 🛠️ **KROK 6: Test manualny**

### Sprawdź czy silnik nie jest mechanicznie zablokowany:

1. **Odłącz zasilanie**
2. **Spróbuj obrócić wał silnika ręcznie**
3. **Jeśli się nie obraca** → silnik jest zablokowany lub uszkodzony
4. **Jeśli się obraca** → problem elektryczny

### Sprawdź LED na sterowniku:

- **Zielone LED** = sterownik włączony
- **Czerwone LED** = błąd (sprawdź połączenia)

## 📋 **KROK 7: Lista kontrolna**

### Przed uruchomieniem:

- [ ] Wszystkie połączenia sprawdzone
- [ ] Zasilacz 6V podłączony
- [ ] Mikroprzełączniki ustawione na 0.5A
- [ ] VM- połączony z GND
- [ ] Kod wgrany na Arduino
- [ ] Monitor szeregowy otwarty

### Podczas testu:

- [ ] Widzę komunikaty w Monitorze Szeregowym
- [ ] LED na sterowniku świeci
- [ ] Silnik reaguje na sygnały
- [ ] Brak dziwnych dźwięków
- [ ] Sterownik nie jest gorący

## 🆘 **KROK 8: Jeśli nic nie pomaga**

### Sprawdź czy:

1. **Silnik nie jest uszkodzony** (spróbuj innego silnika)
2. **Sterownik nie jest uszkodzony** (spróbuj innego sterownika)
3. **Arduino nie jest uszkodzone** (spróbuj innego pinu)

### Kontakt:

- Zrób zdjęcia połączeń
- Zapisz wyniki testów
- Opisz dokładnie co się dzieje
- Sprawdź gwarancję sprzętu

## 💡 **DODATKOWE WSKAZÓWKI**

### Dla silnika 6V:

- **Używaj tylko 6V** (nie 12V!)
- **Ustaw prąd na minimum** (0.5A)
- **Używaj wolnych prędkości** (20-50 kroków/sekundę)
- **Długie impulsy** (100-500ms)

### Bezpieczeństwo:

- **Zawsze wyłącz zasilanie** przed podłączaniem
- **Nie dotykaj** sterownika podczas pracy
- **Sprawdź temperaturę** silnika i sterownika
- **Używaj odpowiedniego zasilacza** z zabezpieczeniem
