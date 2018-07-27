#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP32.h>
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
}
