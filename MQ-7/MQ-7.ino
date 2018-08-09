#include "MQ7.h"

MQ7 mq7(13, 5.0); // (pinMode, Vcc)

void setup() {
  Serial.begin(9600);
}

void loop() {
  String stringCOPPM = String("CO: ") + String(mq7.getPPM()) + String(" ppm");
  Serial.println(stringCOPPM);
  delay(1000);
}
