//DHT11_Thingsboard.ino
#include "ThingsBoard.h"
#include <ESP8266WiFi.h>    // for ESP8266
//#include <WiFi.h>         // for ESP32

#define WIFI_AP             "Mauro Jr.'s Hub"
#define WIFI_PASSWORD       "Nasabayabasan17$$"

#include <DHT.h>

// See https://thingsboard.io/docs/getting-started-guides/helloworld/
// to understand how to obtain an access token
#define TOKEN               "KfSudXuxyFQgU96rHuZH"
#define THINGSBOARD_SERVER  "demo.thingsboard.io"
// Baud rate for debug serial
#define SERIAL_DEBUG_BAUD   115200
#define DHT11_PIN 0
// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11
//#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

DHT dht(DHT11_PIN, DHTTYPE);

// current temperature & humidity, updated in loop()
float t = 0.0;
float h = 0.0;

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
  dht.begin();

  bool status;

  Serial.println("-- Default Test --");
  delayTime = 1000;

  Serial.println();
  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
  InitWiFi();

}

void loop()
{
  delay(10000);            // wait a second
  // Read temperature as Celsius (the default)
    float newT = dht.readTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    //float newT = dht.readTemperature(true);
    // if temperature read failed, don't change t value
    if (isnan(newT)) {
      Serial.println("Failed to read from DHT sensor!");
    }
    else {
      t = newT;
      Serial.println(t);
    }
    // Read Humidity
    float newH = dht.readHumidity();
    // if humidity read failed, don't change h value 
    if (isnan(newH)) {
      Serial.println("Failed to read from DHT sensor!");
    }
    else {
      h = newH;
      Serial.println(h);
    }
  
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
  tb.sendTelemetryFloat("temperature", t);
  tb.sendTelemetryFloat("humidity", h);

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
