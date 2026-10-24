// Module 4 — Eyes and Ears: potentiometer dims an LED.
// Pot: outer pins to 5V and GND, wiper to A0.
// LED: pin 9 (PWM) through a 220 ohm resistor to GND.
const int potPin = A0;
const int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int reading = analogRead(potPin);  // 0-1023
  int brightness = map(reading, 0, 1023, 0, 255);
  analogWrite(ledPin, brightness);
}
