# Hardware Notes

These notes describe **what I've physically checked**, not a complete wiring guide.

## Parts on the bench

| Part | Notes |
| --- | --- |
| Microcontroller | Freenove ESP32-S3-WROOM development board |
| Display | 2.8-inch TFT, 240 × 320, SPI interface, V1.1 marking |
| Tools | Multimeter, breadboard, jumper wires, USB-C data cable |

## Connections tested

With USB disconnected before changing wires:

| ESP32-S3 | TFT | Test |
| --- | --- | --- |
| 3.3V | `VCC` | Display supply connected |
| GND | `GND` | Shared ground connected |
| 3.3V | `LED` | Backlight illuminated white |

A multimeter measured approximately 3.3V at the ESP32 supply. The display showed a white illuminated screen with the backlight connection in place.

These connections were used for an initial test of this specific module. Before using a different display, I'll check that module's voltage and backlight requirements.

## Not yet connected or verified

- Actual display-controller IC (possibly ILI9341, **unconfirmed**)
- Touch-controller IC (possibly XPT2046, **unconfirmed**)
- Exact SPI pin labels and ESP32-S3 GPIO mapping
- Chip-select, data/command and reset signals
- Graphics library configuration
- Touch calibration and input tests

## Next wiring task

I'll verify the TFT module's markings and controller first, then document an actual GPIO-to-display wiring table after making and testing those connections.

**Current limitation:** A white screen is a backlight test, not a completed LCD or touch test.
