// WiFi Weather Station

// Required libraries
#include <ESP8266WiFi.h>

// Libraries
#include "DHT.h"

// Pin
#define DHTPIN 0

// Use DHT11 sensor
#define DHTTYPE DHT11

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE, 15);

// WiFi parameters
const char* ssid = "Mauro Jr.'s Hub";
const char* password = "Nasabayabasan17$$";

// Create an instance of the server
WiFiServer server(80);

// Pin
int output_pin = 5;

void setup() {

  // Start Serial
  Serial.begin(115200);
  delay(10);

// Prepare GPIO5
  pinMode(output_pin, OUTPUT);
  digitalWrite(output_pin, 0);

  // Init DHT
  dht.begin();

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {

  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Reading temperature and humidity
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();

  // Read the first line of the request
 // String req = client.readStringUntil('\r');
 // Serial.println(req);
//  client.flush();

// Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  // Match the request
  if (req.indexOf("/on") != -1){
    digitalWrite(output_pin, 1);
  }
  else if (req.indexOf("/off") != -1) {
    digitalWrite(output_pin, 0);
  }

  client.flush();


  // Prepare the response
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
  s += "<head>";
  s += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
  s += "<meta http-equiv=\"refresh\" content=\"60\" />";
  s += "<script src=\"https://code.jquery.com/jquery-2.1.3.min.js\"></script>";
  s += "<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.4/css/bootstrap.min.css\">";
  s += "<style>body{font-size: 24px;} .voffset {margin-top: 30px;}</style>";
  s += "</head>";

  s += "<h1>Sample IoT Application</h1>";
  s += "<h2>ESP8266 Controlled Lamp</h2>";
  s += "<div class=\"row\">";
  s += "<div class=\"col-md-2\"><input class=\"btn btn-block btn-lg btn-primary\" type=\"button\" value=\"On\" onclick=\"on()\"></div>";
  s += "<div class=\"col-md-2\"><input class=\"btn btn-block btn-lg btn-danger\" type=\"button\" value=\"Off\" onclick=\"off()\"></div>";
  s += "</div></div>";
  s += "<script>function on() {$.get(\"/on\");}</script>";
  s += "<script>function off() {$.get(\"/off\");}</script>";

  //s += "<div class=\"container\">";
  s += "<h1>DHT11 WiFi Demo</h1>";
  s += "<div class=\"row\">";
  s += "<div class=\"col-md-2\">Temperature: </div><div class=\"col-md-2\">" + String(t) + "</div>";
  s += "<div class=\"col-md-2\">Humidity: </div><div class=\"col-md-2\">" + String(h) + "</div>";
  s += "</div>";

  s += "</div>";

  // Send the response to the client
  client.print(s);
  delay(1);
  Serial.println("Client disconnected");

  // The client will actually be disconnected
  // when the function returns and 'client' object is detroyed
}
