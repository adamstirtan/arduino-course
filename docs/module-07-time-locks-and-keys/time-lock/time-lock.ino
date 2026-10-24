// Module 7 — Time Locks and Keys: the time lock.
// RTC: VCC -> 5V, GND -> GND, SDA -> A4, SCL -> A5.
// RC522: SS -> pin 10, RST -> pin 9, MOSI -> pin 11, MISO -> pin 12,
// SCK -> pin 13, VCC -> 3.3V, GND -> GND.
// Green LED -> pin 6, red LED -> pin 5 (each via 220 ohm to GND).
// Passive buzzer -> pin 8.
// Access is granted only when the card UID matches AND the hour
// is between 9 and 17. Replace ALLOWED_UID with the UID your own
// card printed in the rfid-reader sketch.
#include <Wire.h>
#include <RTClib.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
RTC_DS1307 rtc;
MFRC522 rfid(SS_PIN, RST_PIN);

const int greenPin = 6;
const int redPin = 5;
const int buzzerPin = 8;
// Example placeholder UID — replace with your card's UID.
byte allowedUid[4] = {0xDE, 0xAD, 0xBE, 0xEF};

bool uidMatches() {
  if (rfid.uid.size != 4) return false;
  for (byte i = 0; i < 4; i++) {
    if (rfid.uid.uidByte[i] != allowedUid[i]) return false;
  }
  return true;
}

void grant() {
  digitalWrite(greenPin, HIGH);
  tone(buzzerPin, 880);
  delay(300);
  noTone(buzzerPin);
  digitalWrite(greenPin, LOW);
}

void deny() {
  digitalWrite(redPin, HIGH);
  tone(buzzerPin, 220);
  delay(500);
  noTone(buzzerPin);
  digitalWrite(redPin, LOW);
}

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  rtc.begin();
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }
  DateTime now = rtc.now();
  Serial.print("Card presented at ");
  Serial.print(now.hour());
  Serial.print(':');
  Serial.println(now.minute());
  bool ok = uidMatches() && now.hour() >= 9 && now.hour() < 17;
  if (ok) {
    Serial.println("Access granted");
    grant();
  } else {
    Serial.println("Access denied");
    deny();
  }
  rfid.PICC_HaltA();
  delay(500);
}
