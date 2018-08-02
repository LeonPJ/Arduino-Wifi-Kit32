void setup() {
    Serial.begin(9600);
}

void loop() {

    float sensor_volt;
    float RS_gas; // Get value of RS in a GAS
    float ratio; // Get ratio RS_GAS/RS_air
    int sensorValue = analogRead(A0);
    int R0;
    int LPG;
    sensor_volt = (float)sensorValue / 1024 * 5.0;
    RS_gas = (5.0 - sensor_volt) / sensor_volt; // omit *RL
    R0 = 2;
    ratio = R0/RS_gas;  // ratio = RS/R0
    
    LPG = abs(ratio * 1000);// 取正數 
    
    if(LPG <= 400 && LPG >= 0){
      Serial.print("Safe");
      Serial.print(LPG);
      Serial.println("");
      delay(1000);
      }else if(LPG > 400 && LPG < 10000){
        Serial.println("顯示");
        Serial.println(LPG);
        Serial.println("");
        delay(1000);
        }else{
          Serial.println("超過可量測");
          Serial.print(LPG);
          Serial.println("");
          delay(1000);
          }
}
