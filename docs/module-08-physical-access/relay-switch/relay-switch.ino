// Module 8 — Physical Access: relay switch.
// Relay control -> pin 7. On a relay module this is the IN pin;
// for the bare relay in Elegoo Lesson 30, drive the coil through
// the transistor circuit in that lesson's schematic, not directly
// from the pin. Keep the switched circuit separate from the UNO,
// and never exceed the relay's printed rating.
const int relayPin = 7;

void setup() {
  pinMode(relayPin, OUTPUT);
}

void loop() {
  digitalWrite(relayPin, HIGH);
  delay(2000);
  digitalWrite(relayPin, LOW);
  delay(2000);
}
