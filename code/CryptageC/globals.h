#ifndef GLOBALS_H
#define GLOBALS_H

#define ROWS 8
#define COLS 64
#define BITS 8

//Variable of shamir parts, step 1 of the encryption
extern int shamirpartsPayload[ROWS][COLS];
extern int shamirpartsInfo[ROWS][COLS];

//Variable of shamir blended with ceasar code, step 2 of the encryption
extern unsigned short caesarValue;
extern int shamirBlendedCaesarPayload[ROWS][COLS];
extern int shamirBlendedCaesarInfo[ROWS][COLS];

extern int ceasarBinaryPayload[ROWS][COLS][BITS];
extern int ceasarBinaryInfo[ROWS][COLS][BITS];

//Variable of ceasar blended with Xor, step 3 of the encryption
extern unsigned char maskValue;
extern unsigned char maskBits[BITS];
extern int caesarBlendedXorPayload[ROWS][COLS][BITS];
extern int caesarBlendedXorInfo[ROWS][COLS][BITS];

#endif
