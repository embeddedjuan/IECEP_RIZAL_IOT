#include <Adafruit_GFX.h>   // Core graphics library by Adafruit
#include <Arduino_ST7789.h> // Library for ST7789 
#include <SPI.h>

#define TFT_DC    2     // Data/Command
#define TFT_RST   4     // ST7789 Reset
#define TFT_MOSI  23    // SPI data pin
#define TFT_SCLK  18    // SPI sclk pin

Arduino_ST7789 tft = Arduino_ST7789(TFT_DC, TFT_RST);

float p = 3.1415926;
//===============================================================================
//  Initialization
//===============================================================================
void setup() {

  tft.init(240, 240);   // initialize ST7789 chip at 240x240 pixels

  // Paint red/green/blue rectangles
  tft.fillRect(0, 0 , 240, 80, RED);
  tft.fillRect(0, 80 , 240, 160, GREEN);
  tft.fillRect(0, 160 , 240, 240, BLUE);
  delay (1000);

  // large block of text
  tft.fillScreen(BLACK);
  tft.setTextSize(3);   
  tft.setTextColor(WHITE);  
  tft.setCursor(0, 0); 
  tft.println(" IECEP RIZAL");  
  tft.setTextColor(RED);  
  tft.println("ST7789 IPS");  
  tft.setTextColor(YELLOW);  
  tft.println("240X240 IPS");  
  delay(3000);

  // a single pixel
  tft.drawPixel(tft.width() / 2, tft.height() / 2, GREEN);
  delay(1000);

  // line draw test
  testlines(YELLOW);
  delay(1000);

  // optimized lines
  testfastlines(RED, BLUE);
  delay(1000);

  testdrawrects(GREEN);
  delay(1000);

  testfillrects(YELLOW, MAGENTA);
  delay(1000);

  tft.fillScreen(BLACK);
  testfillcircles(10, BLUE);
  testdrawcircles(10, WHITE);
  delay(1000);

  testroundrects();
  delay(1000);

  testtriangles();
  delay(1000);

  mediabuttons();
  delay(1000);
}
//===============================================================================
//  Main
//===============================================================================
void loop() {

  tft.invertDisplay(true);
  delay(500);
  tft.invertDisplay(false);
  delay(500);
}
//===============================================================================
//  Subroutines
//===============================================================================
void testlines(uint16_t color) {
  tft.fillScreen(BLACK);
  for (int16_t x = 0; x < tft.width(); x += 6) {
    tft.drawLine(0, 0, x, tft.height() - 1, color);
  }
  for (int16_t y = 0; y < tft.height(); y += 6) {
    tft.drawLine(0, 0, tft.width() - 1, y, color);
  }
}

void testdrawtext(char *text, uint16_t color) {
  tft.setCursor(0, 0);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}

void testfastlines(uint16_t color1, uint16_t color2) {
  tft.fillScreen(BLACK);
  for (int16_t y = 0; y < tft.height(); y += 5) {
    tft.drawFastHLine(0, y, tft.width(), color1);
  }
  for (int16_t x = 0; x < tft.width(); x += 5) {
    tft.drawFastVLine(x, 0, tft.height(), color2);
  }
}

void testdrawrects(uint16_t color) {
  tft.fillScreen(BLACK);
  for (int16_t x = 0; x < tft.width(); x += 6) {
    tft.drawRect(tft.width() / 2 - x / 2, tft.height() / 2 - x / 2 , x, x, color);
  }
}

void testfillrects(uint16_t color1, uint16_t color2) {
  tft.fillScreen(BLACK);
  for (int16_t x = tft.width() - 1; x > 6; x -= 6) {
    tft.fillRect(tft.width() / 2 - x / 2, tft.height() / 2 - x / 2 , x, x, color1);
    tft.drawRect(tft.width() / 2 - x / 2, tft.height() / 2 - x / 2 , x, x, color2);
  }
}

void testfillcircles(uint8_t radius, uint16_t color) {
  for (int16_t x = radius; x < tft.width(); x += radius * 2) {
    for (int16_t y = radius; y < tft.height(); y += radius * 2) {
      tft.fillCircle(x, y, radius, color);
    }
  }
}

void testdrawcircles(uint8_t radius, uint16_t color) {
  for (int16_t x = 0; x < tft.width() + radius; x += radius * 2) {
    for (int16_t y = 0; y < tft.height() + radius; y += radius * 2) {
      tft.drawCircle(x, y, radius, color);
    }
  }
}

void testtriangles() {
  tft.fillScreen(BLACK);
  int color = 0xF800;
  int t;
  int w = tft.width() / 2;
  int x = tft.height() - 1;
  int y = 0;
  int z = tft.width();
  for (t = 0 ; t <= 15; t++) {
    tft.drawTriangle(w, y, y, x, z, x, color);
    x -= 4;
    y += 4;
    z -= 4;
    color += 100;
  }
}

void testroundrects() {
  tft.fillScreen(BLACK);
  int color = 100;
  int i;
  int t;
  for (t = 0 ; t <= 4; t += 1) {
    int x = 0;
    int y = 0;
    int w = tft.width() - 2;
    int h = tft.height() - 2;
    for (i = 0 ; i <= 16; i += 1) {
      tft.drawRoundRect(x, y, w, h, 5, color);
      x += 2;
      y += 3;
      w -= 4;
      h -= 6;
      color += 1100;
    }
    color += 100;
  }
}

void mediabuttons() {
  // play
  tft.fillScreen(BLACK);
  tft.fillRoundRect(25, 10, 78, 60, 8, WHITE);
  tft.fillTriangle(42, 20, 42, 60, 90, 40, RED);
  delay(500);
  // pause
  tft.fillRoundRect(25, 90, 78, 60, 8, WHITE);
  tft.fillRoundRect(39, 98, 20, 45, 5, GREEN);
  tft.fillRoundRect(69, 98, 20, 45, 5, GREEN);
  delay(500);
  // play color
  tft.fillTriangle(42, 20, 42, 60, 90, 40, BLUE);
  delay(50);
  // pause color
  tft.fillRoundRect(39, 98, 20, 45, 5, RED);
  tft.fillRoundRect(69, 98, 20, 45, 5, RED);
  // play color
  tft.fillTriangle(42, 20, 42, 60, 90, 40, GREEN);
}
