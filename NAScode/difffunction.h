#ifndef DIFFFUNCTION_H
#define DIFFFUNCTION_H

#include "global.h"

void FileToMultiTab(const char *path, char variable[ROWS][COLS][BITS], size_t variable_size);
void FileToTab(const char *path, char *variable, size_t variable_size);
void binaryMask(const char *valeur, unsigned char bits[BITS]);
void unxor(char tab[ROWS][COLS][BITS], char tabBinary[ROWS][COLS][BITS], unsigned char *maskBits);
void binaryToDecimal(char binaryTab[ROWS][COLS][BITS], int decimalTab[ROWS][COLS]);
void printBinary();
void printBinaryUnxor();
void printTabDecimal(int tab[ROWS][COLS], const char *msg);
void decryptCaesar(int tabShamir[ROWS][COLS], int tabDecrypted[ROWS][COLS], int caesarValues);
void printTabShamirsParts(int tab[ROWS][COLS], const char *msg);
int send();

#endif
