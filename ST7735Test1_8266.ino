// Example ST7735Test1_8266.ino
#include <SPI.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library

//ESP32-WROOM
//#define TFT_DC 12 //A0
//#define TFT_CS 13 //CS
//#define TFT_MOSI 14 //SDA
//#define TFT_CLK 27 //SCK
//#define TFT_RST 0 
//#define TFT_MISO 0

//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST);

// ST7735 TFT module connections
#define TFT_RST   D4     // TFT RST pin is connected to NodeMCU pin D4 (GPIO2)
#define TFT_CS    D3     // TFT CS  pin is connected to NodeMCU pin D4 (GPIO0)
#define TFT_DC    D2     // TFT DC  pin is connected to NodeMCU pin D4 (GPIO4)
#define TFT_MOSI  D7     //SDA
#define TFT_CLK   D5     //SCK
// initialize ST7735 TFT library with hardware SPI module
// SCK (CLK) ---> NodeMCU pin D5 (GPIO14)
// MOSI(DIN) ---> NodeMCU pin D7 (GPIO13)
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST);

void setup(void) {
  //tft.initR(INITR_144GREENTAB); // Init ST7735R chip, green tab
  tft.initR(INITR_BLACKTAB);
  //tft.fillScreen(ST77XX_BLACK);
  tft.setRotation(0); // set display orientation 
}
void loop() 
{
  tft.fillScreen(ST77XX_YELLOW);
  print_text(25,30,"HELLO",3,ST77XX_ORANGE);
  print_text(20,70,"WORLD!",3,ST77XX_BLUE);
  delay(5000);
  
  tft.fillScreen(ST77XX_BLACK);
  tft.fillRoundRect(25, 10, 78, 60, 8, ST77XX_WHITE);
  tft.fillTriangle(42, 20, 42, 60, 90, 40, ST77XX_RED);
  delay(5000);
  
  tft.fillScreen(ST77XX_GREEN);
  tft.drawRect(5,5,120,120,ST77XX_RED);
  tft.drawFastHLine(5,60,120,ST77XX_RED);
  tft.drawFastVLine(60,5,120,ST77XX_RED);
  delay(5000);
}
void print_text(byte x_pos, byte y_pos, char *text, byte text_size, uint16_t color) 
{
  tft.setCursor(x_pos, y_pos);
  tft.setTextSize(text_size);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}
