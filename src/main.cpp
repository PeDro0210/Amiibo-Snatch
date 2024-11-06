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
const int SPI_CS_PIN = 5;
const int INT_PIN = 21;

MFRC522 rfid;

void setup() {
  Serial.begin(9600);
  Serial.println(F("init"));
  SPI.begin();
  rfid.PCD_Init(SPI_CS_PIN, INT_PIN);
  Serial.print(F("Reader "));
  Serial.print(F(": "));
  rfid.PCD_DumpVersionToSerial();
  Serial.println();
}

void loop() {
  if (rfid.PICC_IsNewCardPresent()) { // new tag is available
    if (rfid.PICC_ReadCardSerial()) { // NUID has been readed
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
      Serial.print("RFID/NFC Tag Type: ");
      Serial.println(rfid.PICC_GetTypeName(piccType));

      // print UID in Serial Monitor in the hex format
      Serial.print("UID:");
      for (int i = 0; i < rfid.uid.size; i++) {
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(rfid.uid.uidByte[i], HEX);
      }
      Serial.println();

      rfid.PICC_HaltA();      // halt PICC
      rfid.PCD_StopCrypto1(); // stop encryption on PCD
    }
  }
}
