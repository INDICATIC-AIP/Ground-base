#include <stdio.h>
#include "global.h"
#include "difffunction.h"

//The opposite of caesar here is executed

void decryptCaesar(int tabShamir[ROWS][COLS], int tab[ROWS][COLS], int caesarValue) {
    int limit = 125;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            tabShamir[i][j] = ((tab[i][j] - caesarValue) % limit) + limit;
        }
    }
}
