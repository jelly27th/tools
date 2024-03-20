#ifndef HEX2SAE_H
#define HEX2SAE_H

#include <stdio.h>
#include <windows.h>
#include "QString"

extern char FaultField[4];
extern char HexField[16];
extern char DTCType[4];

void Hex2SAE(FILE* ipf, FILE* opf);
void SAE2Hex(FILE* ipf, FILE* opf);
void FilePathCheck(FILE* ipf, FILE* opf);

extern QString SAEFile;
extern QString hexFile;

#endif // HEX2SAE_H
