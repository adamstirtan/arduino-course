// Module 3 — The Door Panel: two buttons, one LED.
// Button A (pin 9) turns the LED on, button B (pin 8) turns it off.
// Both buttons go to GND; INPUT_PULLUP makes unpressed read HIGH,
// so pressed reads LOW.
const int ledPin = 5;
const int buttonApin = 9;
const int buttonBpin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonApin) == LOW) {
    digitalWrite(ledPin, HIGH);
  }
  if (digitalRead(buttonBpin) == LOW) {
    digitalWrite(ledPin, LOW);
  }
}
