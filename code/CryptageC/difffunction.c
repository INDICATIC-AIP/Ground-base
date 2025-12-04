#include <stdio.h>
#include "globals.h"
#include "getChecksum.h"

//Differents function called are defined here, to print, convert ect...

void printTab() {

  // Affichage du tableau
  printf("tab payload\n\n\n");
  for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
          printf("%c", shamirpartsPayload[i][j]);
      }
      printf("\n");
    }
    // Affichage du tableau
printf("tab info\n\n\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", shamirpartsInfo[i][j]);
        }
        printf("\n");
      }
}

void printTabCaesar() {

  // Affichage du tableau
  printf("tab payload ceasar\n\n\n");
  for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
          printf("%d ", shamirBlendedCaesarPayload[i][j]);
      }
      printf("\n");
    }


      printf("tab info ceasar\n\n\n");
      for (int i = 0; i < ROWS; i++) {
          for (int j = 0; j < COLS; j++) {
              printf("%d ", shamirBlendedCaesarInfo[i][j]);
          }
          printf("\n");
        }
}

void binaryMask(unsigned char valeur, unsigned char bits[BITS]) {
    for (int i = BITS - 1; i >= 0; i--) {
        bits[i] = valeur % 2;
        valeur /= 2;
    }
}

//Convert decimal to binary
void decToBinary(int tab[ROWS][COLS][BITS], int tabchiffre[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int nbr = tabchiffre[i][j];
            for (int k = BITS - 1; k >= 0; k--) {
                tab[i][j][k] = nbr % 2; // Récupère le bit
                nbr = nbr / 2;          // Réduit le nombre
            }
        }
      }
}

void printBinary() {

    printf("\n");
    printf("Binary of payload \n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < BITS; k++) {
                printf("%d", ceasarBinaryPayload[i][j][k]);
            }
        }
    }

    printf("\n");
    printf("Binary of info \n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < BITS; k++) {
                printf("%d", ceasarBinaryInfo[i][j][k]);
            }
        }
    }
    printf("\n");
}

void printBinaryWithMask() {

    printf("\n");
    printf("Binary of xored payload \n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < BITS; k++) {
                printf("%d", caesarBlendedXorPayload[i][j][k]);
            }
        }
        printf("\n\n\n");
    }

    printf("Binary of xored info \n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < BITS; k++) {
                printf("%d", caesarBlendedXorInfo[i][j][k]);
            }
        }
        printf("\n\n\n");
    }
}
