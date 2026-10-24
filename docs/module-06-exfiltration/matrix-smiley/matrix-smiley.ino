// Module 6 — Exfiltration: MAX7219 dot-matrix smiley.
// Module: VCC -> 5V, GND -> GND, DIN -> pin 12, CS -> pin 11, CLK -> pin 10.
// Requires the LedControl library (Library Manager).
#include <LedControl.h>

LedControl lc = LedControl(12, 10, 11, 1);

byte smiley[8] = {
  0b00111100,
  0b01000010,
  0b10100101,
  0b10000001,
  0b10100101,
  0b10000001,
  0b01000010,
  0b00111100
};

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, smiley[row]);
  }
}

void loop() {
}
