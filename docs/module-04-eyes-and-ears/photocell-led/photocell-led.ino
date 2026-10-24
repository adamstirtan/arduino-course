// Module 4 — Eyes and Ears: photocell controls LED brightness.
// Voltage divider: 5V -> photocell -> A0 junction -> 10k ohm resistor -> GND.
// Bright light: photocell resistance falls, A0 voltage (and reading) rises.
// LED: pin 9 (PWM) through a 220 ohm resistor to GND.
const int lightPin = A0;
const int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(lightPin);  // 0-1023
  int brightness = map(reading, 0, 1023, 0, 255);
  analogWrite(ledPin, brightness);
  Serial.println(reading);
  delay(100);
}
