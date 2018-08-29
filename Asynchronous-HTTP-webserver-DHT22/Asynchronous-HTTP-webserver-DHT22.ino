#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <DHT.h>

#define DHTPIN 5     // GPIO 5
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino
//int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value
 
const char* ssid = "Smart Home";
const char* password =  "12345678";
 
AsyncWebServer server(80);

 
void setup() {
 
  pinMode(DHTPIN, INPUT);
   dht.begin();
  Serial.begin(9600);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println(WiFi.localIP());
 
  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest * request) {
 
    float temperature = dht.readTemperature();
 
    request->send(200, "text/plain", String(temperature) + " ºC");
  });
 
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest * request) {
 
    float humidity = dht.readHumidity(); 
 
    request->send(200, "text/plain", String(humidity) + " %");
  });
 
  server.begin();
}
 
void loop() {
  
  }
