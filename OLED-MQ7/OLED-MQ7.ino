#include <Wire.h>
#include <SSD1306.h>
#include <MQ7.h>

#define RST_OLED 16                     //OLED Reset引脚，需要手动Reset，否则不显示
#define OLED_UPDATE_INTERVAL 500        //OLED屏幕刷新间隔ms
SSD1306 display(0x3C, 4, 15);           //引脚4，15是绑定在Kit 32的主板上的，不能做其它用

MQ7 mq7(13, 5.0); // (pinMode, resistance)

void setupOLED() {
  pinMode(RST_OLED, OUTPUT);
  digitalWrite(RST_OLED, LOW);        // turn D16 low to reset OLED
  delay(50);
  digitalWrite(RST_OLED, HIGH);       // while OLED is running, must set D16 in high
  /* OLED 初始設定 */
  display.init();
  display.flipScreenVertically();           // 螢幕翻轉
  display.setFont(ArialMT_Plain_10);        // 設定 OLED 字體大小
  display.setTextAlignment(TEXT_ALIGN_LEFT);// 設定 OLED 顯示對其方式
  display.clear();
}

void setup() {
  Serial.begin(9600);
  setupOLED();
}

void loop() {
  String stringCOPPM = String("CO: ") + String(mq7.getPPM()) + String(" ppm"); // 字串組合
  Serial.println(stringCOPPM);
  display.clear();
  display.drawString(0, 10, "hello world");
  display.drawString(10, 20, stringCOPPM);
  display.drawString(20, 30, "hello world2");
  display.display();
  delay(1000);
}
