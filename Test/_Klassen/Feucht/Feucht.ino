#include "dht.h"

dht DHT;
// Sensor
// |     |     |
// Data  V5    G
// 7     V5    G

#define DHT11_PIN 4

void setup(){
  Serial.begin(9600);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Termperatur = ");
  Serial.println(DHT.temperature);
  Serial.print("Feuchtigkeit = ");
  Serial.println(DHT.humidity);
  delay(1000 * 5); //milisecs
}