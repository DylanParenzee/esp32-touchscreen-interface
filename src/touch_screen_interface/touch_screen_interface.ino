
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <Fonts/FreeSansBold12pt7b.h>

// Display control pins
const int TFT_CS = 10;
const int TFT_DC = 9;
const int TFT_RST = 8;

// SPI pins
const int TFT_MOSI = 11;
const int TFT_SCK = 12;

// Create display object
Adafruit_ST7789 tft(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  SPI.begin(TFT_SCK, -1, TFT_MOSI, TFT_CS);

  // Initialise a 240 x 320 display
  tft.init(240, 320);
  //remove color inversion
  tft.invertDisplay(false);

  // Reduce SPI speed to 10 MHz
  tft.setSPISpeed(10000000);
//makes the background black
  tft.fillScreen(ST77XX_BLACK);



// desk control header
tft.setTextColor(ST77XX_WHITE);
tft.setFont(&FreeSansBold12pt7b);
tft.setTextSize(1);
tft.setCursor(22, 30);
tft.print("DESK CONTROL");


// first part designates a square positon and size next part designates color next value designates square coner radius
  tft.fillRoundRect(
  60, 200, 120, 60, 12,
  tft.color565(16, 120, 85)
  );
// first part designates a square positon and size next part designates color next value designates square coner radius
  tft.fillRoundRect(
  60, 80, 120, 60, 16,
  tft.color565(16, 120, 85)
  );

// lamp button text
tft.setFont(&FreeSansBold12pt7b);
tft.setTextSize(1);
tft.setTextColor(ST77XX_WHITE);
tft.setCursor(84, 120);
tft.print("LAMP");



// led  button text
tft.setFont(&FreeSansBold12pt7b);
tft.setTextSize(1);
tft.setTextColor(ST77XX_WHITE);
tft.setCursor(94, 240);
tft.print("LED");




}

void loop() {

}
