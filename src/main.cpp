#include <MFRC522.h> //can get to fix the errors of this one
#include <SPI.h>

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

#define SS_PIN 5   // Adjust according to your ESP32 wiring
#define RST_PIN 22 // Adjust according to your ESP32 wiring

MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();     // Initialize SPI bus
  rfid.PCD_Init(); // Initialize MFRC522 reader
  Serial.println("Place your NTAG215 card on the reader...");
}

// TODO: refactor this function in other place
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
  Serial.println();
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

  // Halt communication with the card
  rfid.PICC_HaltA();
}
