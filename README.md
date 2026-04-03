# 💡 LED Brightness Controller (Arduino)

This project is a simple Arduino-based lamp using an LED and a push button.  
Each time the button is pressed, the LED cycles through different brightness levels.

---

## 🚀 Features

- Uses **PWM (Pulse Width Modulation)** to control LED brightness
- Button press cycles through 4 levels:
  - Off
  - Dim
  - Medium
  - Full Brightness
- Automatically resets back to OFF after the last stage
- Includes basic button debouncing

---

## 🔧 Components Required

- 1x Arduino (Uno or similar)
- 1x LED
- 1x Push Button
- 1x Resistor (220Ω recommended for LED)
- Jumper wires
- Breadboard

---

## ⚙️ How It Works

- The button is connected using `INPUT_PULLUP`
- Each press increases a variable called `stage`
- The `% 4` operator keeps the value between 0–3
- `analogWrite()` is used to set LED brightness

### Brightness Levels

| Stage | PWM Value | Brightness |
|------|----------|------------|
| 0    | 0        | Off        |
| 1    | 50       | Dim        |
| 2    | 130      | Medium     |
| 3    | 255      | Full       |

---

## 🧠 Code Logic

```cpp
stage = (stage + 1) % 4;
