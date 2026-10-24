// Module 5 — Surveillance Kit: sound sensor.
// Module: power to 5V and GND, AO to A0, DO to pin 3.
const int soundAnalogPin = A0;
const int soundDigitalPin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(soundDigitalPin, INPUT);
}

void loop() {
  int level = analogRead(soundAnalogPin);
  int triggered = digitalRead(soundDigitalPin);
  Serial.print(level);
  Serial.print("  threshold: ");
  Serial.println(triggered);
  delay(100);
}
