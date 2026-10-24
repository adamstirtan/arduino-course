// Module 5 — Surveillance Kit: DHT11 temperature and humidity.
// DHT11 module: + -> 5V, - -> GND, S -> pin 2.
// Requires the SimpleDHT library (Library Manager).
#include <SimpleDHT.h>

const int dhtPin = 2;
SimpleDHT11 dht11(dhtPin);

void setup() {
  Serial.begin(9600);
}

void loop() {
  byte temperature = 0;
  byte humidity = 0;
  int err = dht11.read(&temperature, &humidity, NULL);
  if (err == SimpleDHTErrSuccess) {
    Serial.print((int)temperature);
    Serial.print(" C, ");
    Serial.print((int)humidity);
    Serial.println(" %");
  } else {
    Serial.println("DHT11 read failed");
  }
  delay(1500);  // DHT11 only updates about once a second
}
