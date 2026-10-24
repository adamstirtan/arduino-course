// Module 5 — Surveillance Kit: water level sensor.
// Module: power to 5V and GND, analog output to A0.
const int waterPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int level = analogRead(waterPin);
  Serial.println(level);
  delay(200);
}
