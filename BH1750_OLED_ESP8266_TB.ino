//BH1750_OLED_ESP8266_TB.ino
#include <Wire.h>              // include Arduino wire library (required for I2C devices)
#include <Adafruit_GFX.h>      // include Adafruit graphics library
#include <Adafruit_SSD1306.h>  // include Adafruit SSD1306 OLED display driver
#include <BH1750.h>
#include "ThingsBoard.h"
#include <ESP8266WiFi.h>

#define WIFI_AP             "Mauro Jr.'s Hub"
#define WIFI_PASSWORD       "Nasabayabasan17$$"
// See https://thingsboard.io/docs/getting-started-guides/helloworld/
// to understand how to obtain an access token
#define TOKEN               "tLivHjcOobUuz3f6lidz"
#define THINGSBOARD_SERVER  "demo.thingsboard.io"
// Baud rate for debug serial
#define SERIAL_DEBUG_BAUD   115200
#define SCREEN_WIDTH 128 // OLED display width, in pixels

#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET  -1    // define display reset pin
#define SCREEN_ADDRESS 0x3C  //0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//Adafruit_SSD1306 display(-1);  // initialize Adafruit display library

// Initialize ThingsBoard client
WiFiClient espClient;
// Initialize ThingsBoard instance
ThingsBoard tb(espClient);
// the Wifi radio's status
int status = WL_IDLE_STATUS;

BH1750 lightMeter;


void setup(void)
{
// initialize serial for debugging
  Serial.begin(SERIAL_DEBUG_BAUD);
  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
  InitWiFi();
  // initialize the SSD1306 OLED display with I2C address = 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  Wire.begin();
  lightMeter.begin();

  // clear the display buffer.
  display.clearDisplay();
  display.setTextSize(1);   // text size = 1
  display.setTextColor(WHITE, BLACK);  // set text color to white and black background
  display.setTextWrap(false);           // disable text wrap
  display.setCursor(29, 0);
  display.print("BH1750 TEST");
  display.setCursor(0, 16);
  display.print("Light:");
  display.setCursor(80, 16);
  display.print(" lx");
  display.display();        // update the display

}

char _buffer[12];

void loop()
{
  delay(10000);            // wait a second
  float lux = lightMeter.readLightLevel();
  sprintf(_buffer, " %02u.%02u ", (int)lux, (int)(lux * 100) % 100 );
  display.setCursor(37, 16);
  display.print(_buffer);
  display.display();      // update the display

  if (WiFi.status() != WL_CONNECTED) {
    reconnect();
  }

  if (!tb.connected()) {
    // Connect to the ThingsBoard
    Serial.print("Connecting to: ");
    Serial.print(THINGSBOARD_SERVER);
    Serial.print(" with token ");
    Serial.println(TOKEN);
    if (!tb.connect(THINGSBOARD_SERVER, TOKEN)) {
      Serial.println("Failed to connect");
      return;
    }
  }

  Serial.println("Sending data...");

  // Uploads new telemetry to ThingsBoard using MQTT.
  // See https://thingsboard.io/docs/reference/mqtt-api/#telemetry-upload-api
  // for more details

  //tb.sendTelemetryInt("temperature", 22);
  tb.sendTelemetryFloat("lux", lux);

  tb.loop();
  
}

void InitWiFi()
{
  Serial.println("Connecting to AP ...");
  // attempt to connect to WiFi network

  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to AP");
}

void reconnect() {
  // Loop until we're reconnected
  status = WiFi.status();
  if ( status != WL_CONNECTED) {
    WiFi.begin(WIFI_AP, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("Connected to AP");
  }
}
