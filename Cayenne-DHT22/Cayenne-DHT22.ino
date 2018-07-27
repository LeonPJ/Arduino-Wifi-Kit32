#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP32.h>
#include <DHT.h>

#define DHTPIN 5     // GPIO 5
#define DHTTYPE DHT22   // DHT 22  (AM2302)


DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino

float hum;  //Stores humidity value
float temp; //Stores temperature value
unsigned long lastMillis = 0;

// WiFi network info.
char ssid[] = "Smart Home";
char wifiPassword[] = "12345678";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "4ec1c6c0-8fa8-11e8-91b4-c955f66e4774";
char password[] = "2b51c6b5d8a45c68c9616041e6a5485d49fb9fcc";
char clientID[] = "0dc3a250-8fa9-11e8-af94-07170ec969cc";

void setup() {
    Serial.begin(9600);
    Cayenne.begin(username, password, clientID, ssid, wifiPassword);
}

void loop() {
    Cayenne.loop();
    
    hum = dht.readHumidity();
    temp = dht.readTemperature();
    
    if (millis() - lastMillis > 1000) {// Publish data every 1 seconds (1000 milliseconds). Change this value to publish at a different interval.
      lastMillis = millis();

      Serial.print( "Temp: ");
      Serial.print( temp );
      Serial.print( " C, ");
      Serial.print( "Humidity: " );
      Serial.print( hum );
      Serial.print( " %" );
      Serial.println("");
      
      Cayenne.virtualWrite( 0, dht.readTemperature());// push data to Cayenne
      Cayenne.virtualWrite( 1, dht.readHumidity());
            
    }
}
