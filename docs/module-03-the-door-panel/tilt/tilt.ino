// Module 3 — The Door Panel: tilt ball switch.
// Tilt switch: one side to pin 2, other side to GND, INPUT_PULLUP.
// Tilted so the ball closes the switch, pin 2 reads LOW and the LED lights.
const int ledPin = 5;
const int tiltPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(tiltPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(tiltPin) == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
