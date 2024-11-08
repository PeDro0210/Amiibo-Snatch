#include "blockReader/blockReader.h"
#include "webServer/webServer.h"
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

const char *ssid = "Internet de Pedro";
const char *password = "4NJ668300657";

void setup() {
  Serial.begin(96000);
  SPI.begin();     // Initialize SPI bus
  rfid.PCD_Init(); // Initialize MFRC522 reader
                   //
  // WiFi.begin((char *)ssid, (char *)password);
  // while (WiFi.status() != WL_CONNECTED) {
  //  delay(1000);
  // Serial.println("Connecting to WiFi...");
  // }

  // Serial.println("Connected to WiFi");
  // Serial.print("IP Address: ");
  // Serial.println(WiFi.localIP());
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    delay(50); // check for a new amiibo
    return;
  }

  readingRC522();

  // Halt communication with the card
  rfid.PICC_HaltA();
}
