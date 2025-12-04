#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "difffunction.h"
#include "global.h"

//Here differents functions used in the code to print or convert are defined

void FileToMultiTab(const char *path, char variable[ROWS][COLS][BITS], size_t variable_size) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("Erreur to open file");
        printf("%s\n",path );
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    if (file_size > variable_size) { // Check against allocated memory size
        fprintf(stderr, "Error : file to much big\n");
        printf("file size : %ld\n",file_size );
        printf("variable size : %ld\n",variable_size );
        fclose(file);
        return;
    }

    printf("file size : %ld\n",file_size );
    printf("variable size : %ld\n",variable_size );

    fread(variable, 1, file_size, file); // Fill multidimensional array
    fclose(file);
}

//Function to put the files into tabs
void FileToTab(const char *path, char *variable, size_t variable_size) {
    FILE *file = fopen(path, "r");


    fseek(file, 0, SEEK_END); //Go to the end of the file
    long file_size = ftell(file);//Get the size in octects
    rewind(file);//Go back at the beginning of the file

    //Check if the size of the file is correct
    if (file_size >= variable_size) {
        fprintf(stderr, "Error : file to much long long\n");
        fclose(file);
        return;
    }

    //Print size
    //printf("Taille du fichier : %ld octets\n", file_size);
    //printf("Taille disponible dans la variable : %zu octets\n", variable_size);

    //Read all
    size_t bytes_read = fread(variable, 1, file_size, file);
    if (bytes_read != file_size) {
        perror("Error to read file");
        fclose(file);
        return;
    }

    //Terminate the tab with EOF
    variable[file_size] = '\0';

    //Close the tmpFile
    fclose(file);
}

void binaryMask(const char *valeur, unsigned char bits[BITS]) {
    // Convertir la chaîne en un entier numérique (long)
    long numericValue = strtol(valeur, NULL, 10);

    // Remplir le tableau bits avec la représentation binaire
    for (int i = BITS - 1; i >= 0; i--) {
        bits[i] = numericValue % 2; // Prend le reste (0 ou 1)
        numericValue /= 2;          // Divise par 2
    }
}

void binaryToDecimal(char binaryTab[ROWS][COLS][BITS], int decimalTab[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int decimal = 0;
            for (int bit = 0; bit < BITS; bit++) {
                if (binaryTab[row][col][bit] == '1') {
                    decimal += pow(2, BITS - 1 - bit);
                }
            }
            decimalTab[row][col] = decimal;
        }
    }
}

void printBinary() {

    printf("\n");
    printf("Binary of payload \n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < BITS; k++) {
                printf("%c",BitPayload[i][j][k]);
            }
        }
    }

    printf("\n");
    printf("Binary of info \n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < BITS; k++) {
                printf("%c",BitInfo[i][j][k]);
            }
        }
    }
    printf("\n");
}

void printBinaryUnxor() {
  printf("\n");
  printf("Binary of payload unxored \n");
  for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
          for (int k = 0; k < BITS; k++) {
              printf("%c",BitPayloadUnxor[i][j][k]);
          }
      }
  }

  printf("\n");
  printf("Binary of info unxored \n");
  for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
          for (int k = 0; k < BITS; k++) {
              printf("%c",BitInfoUnxor[i][j][k]);
          }
      }
  }
}


//#########################Print decimal parts########################################

void printTabDecimal(int tab[ROWS][COLS], const char *msg) {

  printf("\n %s \n\n\n", msg);
  for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
          printf("%d ", tab[i][j]);
      }
      printf("\n");
    }
}

void printTabShamirsParts(int tab[ROWS][COLS], const char *msg) {

  printf("\n %s \n\n\n", msg);
  for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
          printf("%c", tab[i][j]);
      }
      printf("\n");
    }
}
