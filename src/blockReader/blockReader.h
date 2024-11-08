#ifndef BLOCK_READER
#define BLOCK_READER

#include <MFRC522.h> //can get to fix the errors of this one
#include <SPI.h>
#include <string>

void readPage(int page);

void idPrinting();

extern MFRC522 rfid;

extern std::string id;

#endif // !BLOCK_READER
