// Module 8 — Physical Access: SG90 servo sweep.
// Servo: brown -> GND, red -> 5V, orange signal -> pin 9.
// Requires the Servo library (built into the IDE).
#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(9);
}

void loop() {
  for (int angle = 0; angle <= 180; angle++) {
    servo.write(angle);
    delay(15);
  }
  for (int angle = 180; angle >= 0; angle--) {
    servo.write(angle);
    delay(15);
  }
}
