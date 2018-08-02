#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "8159b992e65449b7a11e78b3f6f7b02c";

char ssid[] = "Smart Home";
char pass[] = "12345678";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  //setting in app Blynk Digital GP21
  Blynk.run();
}

