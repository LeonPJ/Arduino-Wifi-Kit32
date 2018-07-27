//#include <ArduinoOTA.h>
#include <Wire.h>
#include <SSD1306.h>
#include <DHT.h>

/*OLED Arguments*/
#define RST_OLED 16                     //OLED Reset引脚，需要手动Reset，否则不显示
#define OLED_UPDATE_INTERVAL 500        //OLED屏幕刷新间隔ms
SSD1306 display(0x3C, 4, 15);           //引脚4，15是绑定在Kit 32的主板上的，不能做其它用

#define DHTPIN 5     // GPIO 5
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

/*setup oled*/
void setupOLED()
{
  pinMode(RST_OLED, OUTPUT);
  //复位OLED电路
  digitalWrite(RST_OLED, LOW);        // turn D16 low to reset OLED
  delay(50);
  digitalWrite(RST_OLED, HIGH);       // while OLED is running, must set D16 in high
  /* OLED 初始設定 */
  display.init();
  display.flipScreenVertically();           // 倒过来显示内容
  display.setFont(ArialMT_Plain_10);        // 設定 OLED 字體大小
  display.setTextAlignment(TEXT_ALIGN_LEFT);// 設定 OLED 顯示對其方式
  display.clear();
  //display.drawString(0, 0, "Initialize...");
}

void setup()
{
  //pinMode(25, OUTPUT);
  //digitalWrite(25,HIGH);
  pinMode(DHTPIN, INPUT);
  Serial.begin(9600);
  dht.begin();
  setupOLED();
}

void loop()
{
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    //Print temp and humidity values to serial monitor
    Serial.println("");
    Serial.print("Temp: ");
    Serial.print(temp);
    Serial.print(", Humidity: ");
    Serial.print(hum);
    Serial.print(" %");
    //Serial.println(" Celsius");
    Serial.println("");
    delay(1000); //Delay 2 sec.

    String stringtemp =  String(dht.readTemperature());// 把字串常數轉換成 String 物件
    String stringhum =  String(dht.readHumidity()) + "%";
  
    display.clear();
    display.drawString(0, 10, "hello world");
    display.drawString(10, 20, stringtemp);
    display.drawString(20, 30, stringhum);
    display.drawString(30, 40, "hello world2");
    display.display();

}

