#include "blockReader/blockReader.h"

//-------------------------------------
// Typical pin layout used:
//* ------
// *             MFRC522
// *             Reader/PCD   ESP32
// * Signal      Pin          Pin
// * --------------------------------------
// * RST/Reset   RST          21
// * SPI SS      SDA(SS)      5
// * SPI MOSI    MOSI         23
// * SPI MISO    MISO         19
// * SPI SCK     SCK          18
//------ESP32 RFID setting ----------------

void setup() {
  Serial.begin(9600);
  SPI.begin();     // Initialize SPI bus
  rfid.PCD_Init(); // Initialize MFRC522 reader
  Serial.println("Place your amiibo");
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    delay(50); // check for a new amiibo
    return;
  }

  // Read only pages 21 and 22
  readPage(21);
  delay(10); // Small delay for readability
  readPage(22);
  delay(10); // Small delay for readability

  idPrinting();

  // Halt communication with the card
  rfid.PICC_HaltA();
}
