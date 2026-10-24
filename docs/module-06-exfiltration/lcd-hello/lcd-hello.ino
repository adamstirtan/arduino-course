// Module 6 — Exfiltration: 1602 LCD hello world.
// LCD: RS -> pin 7, EN -> pin 8, D4 -> pin 9, D5 -> pin 10,
// D6 -> pin 11, D7 -> pin 12, plus 5V, GND, and a 10k ohm
// potentiometer on the contrast pin (VO).
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Hello, crew");
  lcd.setCursor(0, 1);
  lcd.print("Gear online");
}

void loop() {
}
