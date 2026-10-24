// Module 8 — Physical Access: 28BYJ-48 stepper, quarter turns.
// ULN2003 driver board inputs -> pins 8, 9, 10, 11.
// 2048 steps per full revolution. Pin order matters: the Stepper
// library expects (2048, 8, 10, 9, 11) for this wiring.
// Requires the Stepper library (built into the IDE).
#include <Stepper.h>

Stepper stepper(2048, 8, 10, 9, 11);

void setup() {
  stepper.setSpeed(10);  // rpm
}

void loop() {
  stepper.step(512);   // quarter turn one way
  delay(1000);
  stepper.step(-512);  // quarter turn back
  delay(1000);
}
