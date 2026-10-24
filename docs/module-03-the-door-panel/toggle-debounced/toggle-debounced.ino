// Module 3 — The Door Panel: one button toggles the LED, debounced.
// Uses millis() (not delay()) so the board stays responsive.
const int ledPin = 5;
const int buttonPin = 9;
const unsigned long debounceDelay = 50;

int ledState = LOW;
int buttonState = HIGH;
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
      }
    }
  }
  lastButtonState = reading;
}
