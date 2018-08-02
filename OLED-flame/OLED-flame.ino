#include <Wire.h>
#include <SSD1306.h>

/*OLED Arguments*/
#define RST_OLED 16                     //OLED Reset引脚，需要手动Reset，否则不显示
#define OLED_UPDATE_INTERVAL 500        //OLED屏幕刷新间隔ms
SSD1306 display(0x3C, 4, 15);           //引脚4，15是绑定在Kit 32的主板上的，不能做其它用

int Led = 13; //設定LED接腳在第13孔
int buttonpin = 5; //設定火焰感測器接腳在第5孔
int val; //設定變量val

void setupOLED() {
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
}

void setup() { 
  Serial.begin(9600);
  pinMode(Led,OUTPUT); // LED
  pinMode(buttonpin,INPUT); // sensor
  setupOLED();
}

void loop() {
  val = digitalRead(buttonpin);
  if(val == HIGH) { // 無火花
    Serial.println("1");
    display.clear();
    display.drawString(0, 10, "hello world");
    display.drawString(10, 20, "normal");
    display.drawString(20, 30, "hello world2");
    display.display();
    }else{// 出現火花
      Serial.println("0");
      display.clear();
      display.drawString(0, 10, "hello world");
      display.drawString(10, 20, "Detection Flame");
      display.drawString(20, 30, "hello world2");
      display.display();
      }
}

