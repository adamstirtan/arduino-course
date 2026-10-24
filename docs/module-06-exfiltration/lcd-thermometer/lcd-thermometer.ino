// Module 6 — Exfiltration: LCD thermometer.
// LCD: RS -> pin 7, EN -> pin 8, D4 -> pin 9, D5 -> pin 10,
// D6 -> pin 11, D7 -> pin 12, plus 5V, GND, contrast pot on VO.
// Thermistor divider: 5V -> 10k ohm resistor -> A0 junction ->
// thermistor -> GND. Conversion follows Elegoo Lesson 23
// (Steinhart-Hart); check your thermistor's nominal resistance
// against that lesson before trusting absolute values.
#include <LiquidCrystal.h>
#include <math.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
const int thermistorPin = A0;

double readTemperatureC() {
  int reading = analogRead(thermistorPin);
  double resistance = 10000.0 * (1023.0 / reading - 1.0);
  double logR = log(resistance);
  double tempK = 1.0 / (0.001129148 + 0.000234125 * logR + 0.0000000876741 * logR * logR * logR);
  return tempK - 273.15;
}

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  double tempC = readTemperatureC();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC, 1);
  lcd.print(" C   ");
  lcd.setCursor(0, 1);
  lcd.print("Status: OK      ");
  delay(1000);
}
