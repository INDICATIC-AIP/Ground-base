#ifndef GETCHECKSUM_H
#define GETCHECKSUM_H

#include "globals.h"

void printTab();
void printTabCaesar();
void printBinary();
void printBinaryWithMask();
void caesar(int tab[ROWS][COLS],int tabShamir[ROWS][COLS],int caesarValue);
void decToBinary(int tab[ROWS][COLS][BITS], int tabchiffre[ROWS][COLS]);
void binaryMask(unsigned char valeur, unsigned char bits[BITS]);
void xor(int tab[ROWS][COLS][BITS], int tabBinary[ROWS][COLS][BITS], unsigned char *maskBits);
void shamirParts(int tab[ROWS][COLS], const char *msg);
int send();

#endif
