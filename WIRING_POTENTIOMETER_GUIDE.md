# Wiring Guide: Potentiometer for Stepper Motor Direction and Speed Control

## Overview

This guide explains how to connect a potentiometer to control both the direction and speed of the stepper motor in the JoyLight system.

## Components Needed

- 1x 10kΩ potentiometer (linear or logarithmic)
- 3x male-to-male jumper wires
- Breadboard (optional, for easier connection)

## Wiring Diagram

```
Potentiometer (10kΩ)
┌─────────┐
│   1     │
│   │     │
│   │     │
│   2     │
│   │     │
│   │     │
│   3     │
└─────────┘

Pin 1 (VCC)  → Arduino 5V
Pin 2 (Wiper) → Arduino A0 (Analog Input)
Pin 3 (GND)  → Arduino GND
```

## Step-by-Step Connection

1. **Connect VCC (Pin 1)**

   - Connect one end of a jumper wire to the potentiometer's pin 1
   - Connect the other end to Arduino's 5V pin

2. **Connect Wiper (Pin 2)**

   - Connect one end of a jumper wire to the potentiometer's center pin (wiper)
   - Connect the other end to Arduino's A0 pin (Analog Input 0)

3. **Connect GND (Pin 3)**
   - Connect one end of a jumper wire to the potentiometer's pin 3
   - Connect the other end to Arduino's GND pin

## How It Works

### Direction Control

- **Left side (0-450)**: Motor rotates counter-clockwise (CCW)
- **Middle zone (451-573)**: Motor stops (dead zone)
- **Right side (574-1023)**: Motor rotates clockwise (CW)

### Speed Control

- The further you turn from the center, the faster the motor rotates
- Speed range: 10-200 steps per second
- Minimum speed at the edges of the dead zone
- Maximum speed at the extreme positions

### Continuous Control

- The motor responds in real-time to potentiometer position
- Smooth speed and direction changes
- No need to press buttons or use joystick

## Testing

1. Upload the code to your Arduino
2. Open Serial Monitor (9600 baud)
3. Turn the potentiometer and observe:
   - The "Speed" value on the OLED display
   - The "Direction" status (CW/CCW/STOP)
   - The stepper motor responds immediately to potentiometer position
   - Motor stops when potentiometer is in the middle position

## Control Zones

```
Potentiometer Position:
┌─────────────────────────────────────┐
│  CCW (Left)  │  STOP  │  CW (Right) │
│    0-450     │ 451-573│   574-1023  │
└─────────────────────────────────────┘
```

## Troubleshooting

- **No response**: Check all connections, especially the A0 pin
- **Erratic readings**: Ensure potentiometer is properly connected to 5V and GND
- **Motor not moving**: Check stepper motor connections and potentiometer wiring
- **No direction change**: Verify the potentiometer is connected to A0 pin
- **Motor doesn't stop**: Check if potentiometer is properly centered

## Notes

- The potentiometer now controls both direction AND speed
- The middle position (dead zone) provides a safe stop position
- The further you turn from center, the faster the motor rotates
- This provides intuitive control: left = counter-clockwise, right = clockwise
- The system responds continuously without needing to press buttons
- Perfect for precise positioning and speed control of the 6V stepper motor
