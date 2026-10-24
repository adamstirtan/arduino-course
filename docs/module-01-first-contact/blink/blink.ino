// Module 1 — First Contact: blink an external LED on pin 8.
// Wiring: pin 8 -> 220 ohm resistor -> LED anode (long leg),
// LED cathode (short leg, flat side) -> GND.
const int LED_PIN = 8;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
