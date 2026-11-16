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

## SPI display connections tested

| ESP32-S3 | TFT module | Function |
| --- | --- | --- |
| GPIO 11 | `SDI (MOSI)` | Data from ESP32 to display |
| GPIO 12 | `SCK` | SPI clock |
| GPIO 10 | `CS` | Display chip select |
| GPIO 9 | `DC` | Data/command select |
| GPIO 8 | `RESET` | Display reset |

These connections, along with the supply and backlight wiring, produced a full-screen blue display with the Adafruit ST7789 library using `tft.init(240, 320)`, `tft.invertDisplay(false)` and the 10 MHz SPI setting.

## Not yet connected or verified

- Actual display-controller IC marking (**unconfirmed**, although the ST7789 library works)
- Touch-controller IC (possibly XPT2046, **unconfirmed**)
- Touch controller wiring and interaction
- Touch calibration and input tests

## Next wiring task

I'll verify the controller marking when possible and then proceed with an isolated touchscreen input test in a future lesson.

**Current limitation:** Drawing a full-screen colour works, but touchscreen input has not been tested.
