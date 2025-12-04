#ifndef GLOBALS_H
#define GLOBALS_H

#define ROWS 8
#define COLS 64
#define BITS 8

//############################Global variables declaration##########################

//Tab received
extern char BitPayload[ROWS][COLS][BITS];
extern char BitInfo[ROWS][COLS][BITS];
extern char CaesarValue[12];
extern int CaesarValueint;
extern char Mask[BITS];

//Convert decimal value into binary
extern unsigned char maskBits[BITS];

//Variables that's contains the payload and info binary unxored
extern char BitPayloadUnxor[ROWS][COLS][BITS];
extern char BitInfoUnxor[ROWS][COLS][BITS];

//Variables that's contains the payload and info binary unxored in decimal
extern int BinaryUnxoredToDecimalPayload[ROWS][COLS];
extern int BinaryUnxoredToDecimalInfo[ROWS][COLS];

//Variable that's contains the payload and info decimal value after caesar code reused, so contains shamir's parts
extern int ShamirPartsPayload[ROWS][COLS];
extern int ShamirPartsInfo[ROWS][COLS];

extern char PayloadHash[COLS];

#endif
