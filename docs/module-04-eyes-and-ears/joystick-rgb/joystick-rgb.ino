// Module 4 — Eyes and Ears: joystick drives RGB colour.
// Joystick: GND -> GND, +5V -> 5V, VRx -> A0, VRy -> A1, SW -> pin 2 (INPUT_PULLUP).
// RGB LED (common cathode): blue pin 3, green pin 5, red pin 6, common to GND,
// each colour through a 220 ohm resistor.
// X controls red, Y controls green; pressing the stick toggles blue.
const int xPin = A0;
const int yPin = A1;
const int swPin = 2;
const int redPin = 6;
const int greenPin = 5;
const int bluePin = 3;

int blueState = 0;
int lastSwState = HIGH;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(swPin, INPUT_PULLUP);
}

void loop() {
  int x = analogRead(xPin);
  int y = analogRead(yPin);
  analogWrite(redPin, map(x, 0, 1023, 0, 255));
  analogWrite(greenPin, map(y, 0, 1023, 0, 255));
  int sw = digitalRead(swPin);
  if (sw == LOW && lastSwState == HIGH) {
    blueState = !blueState;
    analogWrite(bluePin, blueState ? 255 : 0);
    delay(200);  // simple debounce for the stick press
  }
  lastSwState = sw;
}
