void setup() {
    Serial.begin(9600);
}

void loop() {

    float sensor_volt;
    float RS_gas; // Get value of RS in a GAS
    float ratio; // Get ratio RS_GAS/RS_air
    float R0 = 4.59;
    int LPG;
    int sensorValue = analogRead(13);
    
    sensor_volt=(float)sensorValue/1024*5.0;
    RS_gas = (5.0-sensor_volt)/sensor_volt; // omit *RL
    ratio = RS_gas/R0;  // ratio = RS/R0
    if(ratio > 0.7522){
      Serial.println("ppm 小於353");
      Serial.println(ratio);
      }else if(0.1493 <= ratio && ratio <= 0.7522){
        LPG = (0.821 - ratio) / (2.631 * 0.0001) + 353;
        Serial.println(LPG);
        }else{
          Serial.println("超過可量測範圍");
          Serial.println(ratio);
          }
    delay(1000);
}
