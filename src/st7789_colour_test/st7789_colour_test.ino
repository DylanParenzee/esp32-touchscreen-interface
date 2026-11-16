// First full-screen TFT colour test
// Guided learning sketch for Freenove ESP32-S3 + 2.8-inch SPI TFT
// Verified result: full-screen blue after disabling colour inversion.
// The exact display controller IC marking has not been confirmed.

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

const int TFT_CS = 10;
const int TFT_DC = 9;
const int TFT_RST = 8;
const int TFT_MOSI = 11;
const int TFT_SCK = 12;

Adafruit_ST7789 tft(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  SPI.begin(TFT_SCK, -1, TFT_MOSI, TFT_CS);
  tft.init(240, 320);
  tft.invertDisplay(false);
  tft.setSPISpeed(10000000);
  tft.fillScreen(ST77XX_BLUE);
}

void loop() {
}
