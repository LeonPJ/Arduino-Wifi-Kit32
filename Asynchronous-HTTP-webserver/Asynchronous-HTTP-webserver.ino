/*open a web browser and type the following on the address bar, changing {yourEspIp} by the IP you have just copied.
http://{yourEspIp}/hello*/

#include <WiFi.h>
//#include <FS.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
 
const char* ssid = "Smart Home";
const char* password =  "12345678";
 
AsyncWebServer server(80);
 
void setup(){
  Serial.begin(9600);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println(WiFi.localIP());
 
  server.on("/hello", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Hello World");
  });
 
  server.begin();
}
 
void loop(){
}
