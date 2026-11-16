# ESP32-S3 Touchscreen Interface

I'm building a touchscreen interface with an ESP32-S3 as part of learning C++ and embedded software engineering.

I started with a Freenove ESP32-S3 development board and a small 2.8-inch TFT display. Rather than jumping straight into a finished interface, I'm working through the basics: checking the power supply, proving that I can upload code, getting the display to communicate over SPI, and eventually handling touch input.

My longer-term goal is to use what I learn here in bigger projects, including a facial-recognition door lock. This repository is a record of what I actually tested, the problems I ran into, and how I worked through them.

## Current progress

**In progress — SPI graphics working: full-screen blue confirmed with the ST7789 library and colour inversion disabled. Touch input has not yet been tested.**

| Milestone | Result |
| --- | --- |
| Set up ESP32-S3 in Arduino IDE | Completed |
| Upload and run a basic C++ sketch | Completed |
| Confirm readable output in Serial Monitor | Completed |
| Measure the board's 3.3V supply | Completed |
| Power the TFT backlight | Completed — white illuminated screen |
| Send drawing commands to TFT over SPI | Completed guided first graphics test — full-screen blue |
| Read touchscreen input | Not started |
| Build a simple graphical interface | Not started |

The first ILI9341 graphics test coloured only part of the panel and left static below. Testing with Adafruit ST7789 filled the full panel, although the requested blue initially appeared yellow. Adding `tft.invertDisplay(false)` produced a full-screen blue result. This demonstrates a compatible software configuration, **not definitive identification of the controller IC**. Touch input has not been tested.

## Hardware

- Freenove ESP32-S3-WROOM development board
- 2.8-inch 240 × 320 TFT module with SPI interface, board marked V1.1
- USB-C data cable, jumper wires, breadboard and multimeter

The display controller's marking is **not yet confirmed**, but the Adafruit ST7789 library produces a full-screen image using `tft.init(240, 320)` and `tft.invertDisplay(false)`. The touch-controller part number also remains unverified.

See [hardware notes](docs/HARDWARE.md) for the connections tested so far and what remains to be verified.

## Software

- C++ using Arduino IDE
- ESP32 board package by Espressif Systems
- Board target used: `ESP32S3 Dev Module`
- `USB CDC On Boot` enabled for the serial-output test
- Serial Monitor set to **115200 baud**
- Adafruit GFX + Adafruit ST7735/ST7789 library for the first working graphics test

### First working test

My first successful upload was a small serial-output sketch. It prints a startup message and then repeats a message every second, which let me confirm that the board was actually running my program.

The [serial smoke-test sketch](src/serial_smoke_test/serial_smoke_test.ino) is the guided example I uploaded and verified on the board. It's not touchscreen code.

### First successful graphics test

I followed a guided [ST7789 full-screen colour test](src/st7789_colour_test/st7789_colour_test.ino). With SPI wires connected, the first driver choice only updated part of the screen. The alternative driver filled the display, and switching off inversion gave the intended blue. The sketch in this repository records the working configuration presented during the exercise.

## Development record

- [Development log](CHANGELOG.md) — dated tests, observations and troubleshooting
- [Hardware notes](docs/HARDWARE.md) — components, tested power connections and outstanding checks
- [Learning portfolio](https://github.com/DylanParenzee/embedded-cpp-learning) — my broader Arduino and C++ progress

## Next milestone

With the first full-screen graphics test working, the next milestone is to confirm the display/controller details and progress to controlled graphics and, in a later lesson, touch input.

I'll add photos, diagrams and more code as I test each part of the system. For now, this repository documents an early working display milestone, not a completed interface.
