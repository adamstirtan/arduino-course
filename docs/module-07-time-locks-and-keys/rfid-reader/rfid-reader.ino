// Module 7 — Time Locks and Keys: RC522 RFID reader.
// RC522: SDA (SS) -> pin 10, RST -> pin 9, MOSI -> pin 11,
// MISO -> pin 12, SCK -> pin 13, VCC -> 3.3V (NOT 5V), GND -> GND.
// Requires the MFRC522 library (Library Manager).
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  Serial.println("Hold a card near the reader...");
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }
  Serial.print("UID: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(rfid.uid.uidByte[i], HEX);
  }
  Serial.println();
  rfid.PICC_HaltA();
}
