#include <stdio.h>
#include "getChecksum.h"
#include "globals.h"

//Do xor on bits

void xor(int tab[ROWS][COLS][BITS], int tabBinary[ROWS][COLS][BITS], unsigned char *maskBits) {

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      for (int k = 0; k < BITS; k++) {
        tab[i][j][k] = tabBinary[i][j][k] ^ maskBits[k];
      }
    }
  }
}
