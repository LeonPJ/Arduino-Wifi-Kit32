#include <DHT.h>

#define DHTPIN 5     // GPIO 5
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino
//int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
  pinMode(DHTPIN, INPUT);
  Serial.begin(9600);
  dht.begin();
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
    delay(2000); //Delay 2 sec.
}

