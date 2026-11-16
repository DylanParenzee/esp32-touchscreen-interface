# Development Log

## 17 November 2026 — First full-screen colour over SPI

**Result: first graphics milestone working (guided test).**

I connected my ESP32-S3 and 2.8-inch TFT using SPI, then uploaded a colour-fill sketch. With the initial Adafruit ILI9341 library, the upper portion of the display changed colour but the lower portion remained white or showed multicoloured static. I was worried the screen might be damaged.

I tested an alternative software configuration with the Adafruit ST7789 driver. This time the entire screen was filled, but the requested blue appeared yellow. Adding `tft.invertDisplay(false)` after `tft.init(240, 320)` corrected the displayed colour: the **entire screen showed blue**.

**What I learned:** A working backlight alone doesn't confirm LCD communication. Partial graphics and wrong colours can arise from driver or controller configuration, not necessarily broken hardware. Changing one setting at a time helped isolate the problem.

**Verified:** Complete blue fill using the ST7789 library and the guided wiring. The exact display controller chip and touch input are not yet verified.

**Next:** Explain the fault-finding logic in my own words; later test additional graphics and touch input.

## 15 November 2026 — Getting the ESP32-S3 and TFT powered up

I started with the Freenove ESP32-S3 and a 2.8-inch TFT module. My first goal was to prove that the hardware was powered correctly and that I could upload and run a program.

### Tests completed

1. Measured **3.3V** between the ESP32's 3.3V and GND pins using a multimeter.
2. Connected the TFT's `VCC` and `GND` to the ESP32 supply and ground. The screen stayed dark.
3. Connected the TFT's `LED` backlight input to 3.3V. The screen illuminated white.
4. Installed the Espressif board support in Arduino IDE and selected `ESP32S3 Dev Module`.
5. Uploaded a guided serial-output sketch, then checked the Arduino IDE upload output.
6. Initially had trouble getting readable Serial Monitor output. I checked the serial configuration, including the baud rate and USB CDC setting, and eventually got the sketch printing `Program running...` repeatedly.

### What I learned

The screen's backlight working doesn't mean the ESP32 is successfully communicating with the display. I also learned to separate an **upload problem** from a **serial-monitor problem**: the upload itself had succeeded even though the expected text wasn't visible at first.

### Verified outcome

- ESP32-S3 successfully uploaded and ran the serial test.
- Serial Monitor displayed recurring text at 115200 baud.
- TFT backlight illuminated white.
- No graphics or touch input have been tested yet.

### Next session

Verify the display controller, map the display's SPI pins to safe ESP32-S3 GPIOs, and test the first drawing command.
