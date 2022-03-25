//BME280_ThingsBoard.ino
#include <Wire.h>              // include Arduino wire library (required for I2C devices)
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "ThingsBoard.h"
#include <ESP8266WiFi.h>    // for ESP8266
//#include <WiFi.h>             // for ESP32
#define SEALEVELPRESSURE_HPA (1013.25)

#define WIFI_AP             "Mauro Jr.'s Hub"
#define WIFI_PASSWORD       "Nasabayabasan17$$"

// See https://thingsboard.io/docs/getting-started-guides/helloworld/
// to understand how to obtain an access token
#define TOKEN               "boYk865MEqPIGUSkKMXb"
#define THINGSBOARD_SERVER  "demo.thingsboard.io"
// Baud rate for debug serial
#define SERIAL_DEBUG_BAUD   115200

Adafruit_BME280 bme; // I2C

// Initialize ThingsBoard client
WiFiClient espClient;
// Initialize ThingsBoard instance
ThingsBoard tb(espClient);
// the Wifi radio's status
int status = WL_IDLE_STATUS;

unsigned long delayTime;

void setup(void)
{
// initialize serial for debugging
  Serial.begin(SERIAL_DEBUG_BAUD);
  Serial.println(F("BME280 test"));

  bool status;

  // default settings
  // (you can also pass in a Wire library object like &Wire2)
  status = bme.begin(0x76);  
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  Serial.println("-- Default Test --");
  delayTime = 1000;

  Serial.println();
  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
  InitWiFi();

  Wire.begin();

}

void loop()
{
  delay(10000);            // wait a second
  //float lux = lightMeter.readLightLevel();
  float temp = bme.readTemperature();
  float pres = bme.readPressure() / 100.0F;
  float alt = bme.readAltitude(SEALEVELPRESSURE_HPA);
  float hum = bme.readHumidity();
  
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
  //tb.sendTelemetryFloat("lux", lux);
  tb.sendTelemetryFloat("temperature", temp);
  tb.sendTelemetryFloat("pressure", pres);
  tb.sendTelemetryFloat("altitude", alt);
  tb.sendTelemetryFloat("humidty", hum);

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
