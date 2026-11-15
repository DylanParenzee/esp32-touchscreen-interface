# ESP32-S3 Touchscreen Interface

I'm building a touchscreen interface with an ESP32-S3 as part of learning C++ and embedded software engineering.

I started with a Freenove ESP32-S3 development board and a small 2.8-inch TFT display. Rather than jumping straight into a finished interface, I'm working through the basics: checking the power supply, proving that I can upload code, getting the display to communicate over SPI, and eventually handling touch input.

My longer-term goal is to use what I learn here in bigger projects, including a facial-recognition door lock. This repository is a record of what I actually tested, the problems I ran into, and how I worked through them.

## Current progress

**In progress — serial communication and TFT backlight tested; SPI display communication is next.**

| Milestone | Result |
| --- | --- |
| Set up ESP32-S3 in Arduino IDE | Completed |
| Upload and run a basic C++ sketch | Completed |
| Confirm readable output in Serial Monitor | Completed |
| Measure the board's 3.3V supply | Completed |
| Power the TFT backlight | Completed — white illuminated screen |
| Send drawing commands to TFT over SPI | Not started |
| Read touchscreen input | Not started |
| Build a simple graphical interface | Not started |

A white screen **only confirms that the backlight illuminates**. I haven't displayed graphics or tested the touchscreen yet.

## Hardware

- Freenove ESP32-S3-WROOM development board
- 2.8-inch 240 × 320 TFT module with SPI interface, board marked V1.1
- USB-C data cable, jumper wires, breadboard and multimeter

The display controller is **not yet confirmed**. ILI9341 is a candidate for this style of module, and the touch-controller part number still needs verification before choosing libraries.

See [hardware notes](docs/HARDWARE.md) for the connections tested so far and what remains to be verified.

## Software

- C++ using Arduino IDE
- ESP32 board package by Espressif Systems
- Board target used: `ESP32S3 Dev Module`
- `USB CDC On Boot` enabled for the serial-output test
- Serial Monitor set to **115200 baud**

### First working test

My first successful upload was a small serial-output sketch. It prints a startup message and then repeats a message every second, which let me confirm that the board was actually running my program.

The [serial smoke-test sketch](src/serial_smoke_test/serial_smoke_test.ino) is the guided example I uploaded and verified on the board. It's not touchscreen code.

## Development record

- [Development log](CHANGELOG.md) — dated tests, observations and troubleshooting
- [Hardware notes](docs/HARDWARE.md) — components, tested power connections and outstanding checks
- [Learning portfolio](https://github.com/DylanParenzee/embedded-cpp-learning) — my broader Arduino and C++ progress

## Next milestone

Identify the TFT controller and pin labels, connect the ESP32-S3 and display over SPI, and get a colour or simple shape onto the screen. After that, I'll work on reading touch coordinates.

I'll add photos, diagrams and more code as I test each part of the system. For now, this repository shows the starting point, not a completed interface.
