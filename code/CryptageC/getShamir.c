#include <stdio.h>
#include <stdlib.h>
#include "getChecksum.h"
#include "globals.h"

//Get the shamirs parts in the file created by the python script ShamirsParts.py

void shamirParts(int tab[ROWS][COLS], const char *msg) {
    FILE *file;

    const char *filename = msg;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error : cannot open the file %s\n", filename);
        return; // Return since fopen failed
    }

   // printf("file : %s opened \n",filename );

    int c = 0, i = 0, j = 0;

    while (!feof(file)) {
        c = fgetc(file);
        if (c == EOF) break;

        if (c == '\n' || c == '\r' || c == ' ') {
            continue;
        }

        tab[i][j] = c;
        j++;

        if (j == COLS) {
            j = 0;
            i++;
            if (i == ROWS) break;
        }
    }

    fclose(file);
}
