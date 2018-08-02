int Led = 13; //設定LED接腳在第13孔
int buttonpin = 5; //設定火焰感測器接腳在第3孔
int val; //設定變量val

void setup() { 
  Serial.begin(9600);
  pinMode(Led,OUTPUT); // LED
  pinMode(buttonpin,INPUT); // sensor
}

void loop() {
  val = digitalRead(buttonpin);
  //Serial.println(val);
  if(val == HIGH) { 
    Serial.println("1");
    }else{
      Serial.println("0");
      }
}

