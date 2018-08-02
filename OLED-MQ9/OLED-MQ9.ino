#include <Wire.h>
#include <SSD1306.h>

/*OLED Arguments*/
#define RST_OLED 16                     //OLED Reset引脚，需要手动Reset，否则不显示
#define OLED_UPDATE_INTERVAL 500        //OLED屏幕刷新间隔ms
SSD1306 display(0x3C, 4, 15);           //引脚4，15是绑定在Kit 32的主板上的，不能做其它用

float sensor_volt;
float RS_gas; // Get value of RS in a GAS
float ratio; // Get ratio RS_GAS/RS_air
float R0 = 5;
int CO;
int sensorValue = analogRead(13);

void setupOLED()
{
  pinMode(RST_OLED, OUTPUT);
  //复位OLED电路
  digitalWrite(RST_OLED, LOW);        // turn D16 low to reset OLED
  delay(50);
  digitalWrite(RST_OLED, HIGH);       // while OLED is running, must set D16 in high
  /* OLED 初始設定 */
  display.init();
  display.flipScreenVertically();           // 螢幕翻轉
  display.setFont(ArialMT_Plain_10);        // 設定 OLED 字體大小
  display.setTextAlignment(TEXT_ALIGN_LEFT);// 設定 OLED 顯示對其方式
  display.clear();
  //display.drawString(0, 0, "Initialize...");
}

void setup() {
    Serial.begin(9600);
    setupOLED();
}

void loop() {
    sensor_volt=(float)sensorValue/1024*5.0;
    RS_gas = (5.0-sensor_volt)/sensor_volt; // omit *RL
    ratio = RS_gas/R0;  // ratio = RS/R0
    if(ratio > 0.7522){
      Serial.println("ppm 小於353");
      display.clear();
      display.drawString(0, 10, "hello world");
      display.drawString(10, 20, "ppm < 353");
      display.drawString(20, 30, "hello world2");
      display.display();
      }else if(0.1493 <= ratio && ratio <= 0.7522){
        CO = (0.821 - ratio) / (2.631 * 0.0001) + 353;
        Serial.println(CO);
        String stringCOPPM =  String(CO);
        display.clear();
        display.drawString(0, 10, "hello world");
        display.drawString(10, 20, stringCOPPM);
        display.drawString(20, 30, "hello world2");
        display.display();
        }else{
          Serial.println("超過可量測範圍");
          display.clear();
          display.drawString(0, 10, "hello world");
          display.drawString(10, 20, "OVER MEASURE");
          display.drawString(20, 30, "hello world2");
          display.display();
          }
    delay(1000);
}
