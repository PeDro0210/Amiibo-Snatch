#ifndef BLOCK_READER
#define BLOCK_READER

#include <MFRC522.h> //can get to fix the errors of this one
#include <SPI.h>
#include <string>

std::string getModelId();
void readingRC522();

void readPage(int page);

void idPrinting();

void resetId();

extern MFRC522 rfid;

extern std::string id_model;

#endif // !BLOCK_READER
