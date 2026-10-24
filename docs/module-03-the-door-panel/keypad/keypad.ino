// Module 3 — The Door Panel: 4x4 membrane keypad.
// Requires the Keypad library (Library Manager, search "Keypad").
// Keypad pins 1-8 -> UNO pins 9, 8, 7, 6, 5, 4, 3, 2.
// If keys print as the wrong character, transpose the keymap below
// to match your keypad's layout before rewiring anything.
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    Serial.println(key);
  }
}
