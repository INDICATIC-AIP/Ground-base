#include <stdio.h>
#include <stdlib.h>
#include "getChecksum.h"
#include "globals.h"

//Realise the caesar code

void caesar(int tab[ROWS][COLS], int tabShamir[ROWS][COLS],int caesarValue) {
  int limit = 125;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
        int index = tabShamir[i][j] + caesarValue;
        int validIndex = index % limit;
        tab[i][j] = validIndex;
    }
  }
}
