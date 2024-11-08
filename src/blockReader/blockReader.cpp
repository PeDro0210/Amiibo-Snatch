#include "blockReader.h"

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

#define SS_PIN 5
#define RST_PIN 22

MFRC522 rfid(SS_PIN, RST_PIN);

std::string id;

void byteCaster(byte buffer[]) {
  int pos = 0;

  for (byte i = 0; i < 4; i++) {
    // TODO: see how to cast bytes to char
  }
}

void idPrinting() { Serial.println("yes"); }

void readPage(int page) {
  byte buffer[18]; // Buffer to hold read data (4 bytes per page)
  byte size = sizeof(buffer);

  MFRC522::StatusCode status =
      rfid.MIFARE_Read(page, buffer, &size); // best line 2024

  if (status != MFRC522::STATUS_OK) {
    Serial.print("Error reading page ");
    Serial.print(page);
    Serial.print(": ");
    Serial.println(rfid.GetStatusCodeName(status));
    return;
  }

  // Print the page data
  Serial.print("Page ");
  Serial.print(page);
  Serial.print(": ");
  for (byte i = 0; i < 4; i++) {
    Serial.print(buffer[i],
                 HEX); // TODO:add it in to byte array for later handleling
    Serial.print(" ");
  }

  byteCaster(buffer);
  Serial.println();
}
