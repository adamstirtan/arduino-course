// Module 7 — Time Locks and Keys: RTC clock.
// RTC module: VCC -> 5V, GND -> GND, SDA -> A4, SCL -> A5.
// Requires the RTClib library (Library Manager).
// NOTE: the rtc.adjust() line sets the clock to the sketch's
// compile time. Run it once, then comment it out and re-upload,
// or the clock will reset on every power-up.
#include <Wire.h>
#include <RTClib.h>

RTC_DS1307 rtc;

void setup() {
  Serial.begin(9600);
  rtc.begin();
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop() {
  DateTime now = rtc.now();
  Serial.print(now.year());
  Serial.print('/');
  Serial.print(now.month());
  Serial.print('/');
  Serial.print(now.day());
  Serial.print(' ');
  Serial.print(now.hour());
  Serial.print(':');
  Serial.print(now.minute());
  Serial.print(':');
  Serial.println(now.second());
  delay(1000);
}
