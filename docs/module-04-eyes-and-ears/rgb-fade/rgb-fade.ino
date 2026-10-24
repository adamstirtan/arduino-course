// Module 4 — Eyes and Ears: RGB LED colour fade.
// Common cathode RGB LED: common to GND, each colour through a
// 220 ohm resistor: blue to pin 3, green to pin 5, red to pin 6.
const int redPin = 6;
const int greenPin = 5;
const int bluePin = 3;

void setColor(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

void fade(int fromR, int fromG, int fromB, int toR, int toG, int toB) {
  for (int i = 0; i <= 255; i++) {
    setColor(map(i, 0, 255, fromR, toR),
             map(i, 0, 255, fromG, toG),
             map(i, 0, 255, fromB, toB));
    delay(10);
  }
}

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  fade(255, 0, 0, 0, 255, 0);    // red -> green
  fade(0, 255, 0, 0, 0, 255);    // green -> blue
  fade(0, 0, 255, 255, 0, 0);    // blue -> red
}
