#include <WiFi.h>
#include <PubSubClient.h>
 
const char* ssid = "Smart Home";
const char* password =  "12345678";
const char* mqttServer = "m13.cloudmqtt.com";
const int mqttPort = 15420;
const char* mqttUser = "ndvejcug";
const char* mqttPassword = "tvqkF8-L8Tnm";
 
WiFiClient espClient;
PubSubClient client(espClient);
 
void setup() {
 
  Serial.begin(9600);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP32Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
 
  client.publish("esp/test", "Hello from ESP32");
 
}
 
void loop() {
  client.loop();
}
