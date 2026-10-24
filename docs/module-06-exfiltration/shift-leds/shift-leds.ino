// Module 6 — Exfiltration: 74HC595 shift register, eight LEDs.
// Latch -> pin 11, clock -> pin 9, data -> pin 12.
// Chip outputs each go through a 220 ohm resistor to an LED, then to GND.
const int latchPin = 11;
const int clockPin = 9;
const int dataPin = 12;

byte leds = 0;

void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  leds = 0;
  updateShiftRegister();
  delay(500);
  for (int i = 0; i < 8; i++) {
    bitSet(leds, i);
    updateShiftRegister();
    delay(500);
  }
}
