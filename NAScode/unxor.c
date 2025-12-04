#include <stdio.h>
#include "global.h"
#include "difffunction.h"

//Here the bits received are unxored

void unxor(char tab[ROWS][COLS][BITS], char tabBinary[ROWS][COLS][BITS], unsigned char *maskBits) {

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      for (int k = 0; k < BITS; k++) {
        tab[i][j][k] = tabBinary[i][j][k] ^ maskBits[k];
      }
    }
  }
}
