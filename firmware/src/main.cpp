#include "blockReader/blockReader.h"
#include "webServer/webServer.h"

#include <WiFi.h>
#include <WiFiMulti.h>

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

char *ssid = "Internet de Pedro"; // Reemplaza con tu SSID de Wi-Fi
char *password = "4NJ667300657";  // Reemplaza con tu contraseña de Wi-Fi

void setup() {
  Serial.begin(
      9600);   // Asegúrate de que el monitor serial esté configurado a 115200
  SPI.begin(); // Inicializa el bus SPI
  rfid.PCD_Init(); // Inicializa el lector MFRC522

  // Conexión a Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Conectando a Wi-Fi ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\n¡Conectado a Wi-Fi!");
  Serial.println("Dirección IP: ");
  Serial.println(WiFi.localIP());

  endpoints();
  server.begin();
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    delay(50); // verifica si hay una nueva tarjeta

    return;
  }

  readingRC522();
  idPrinting();
  // Detiene la comunicación con la tarjeta
  rfid.PICC_HaltA();
}
