
const int pin = A0;
const int n = 1000;  // sample 採樣 1000 次
void setup() {
  Serial.begin(9600);
  for(int i=0; i< 543; i++) analogRead(pin); // 熱身 :-)
  Serial.println(String("Sample ") + n + " times, pin=" + pin);
  Serial.flush( );
  delay(568);
}
void loop( ) { // 
  unsigned long begt, runt, total;
  total = 0;  // clear before sampling
  begt = micros();
  for(int i=0; i< n; i++) {
     total += analogRead(pin);
  }
  runt = micros() - begt;  // elapsed time
  Serial.println(String("Average=") + total/n);
  Serial.print(String("Time per sample: ")+runt/1.0/n +"us");
  Serial.println(String(", Frequency: ")+1000000.0/runt*n +" Hz");
  delay(5566);
}// loop(
