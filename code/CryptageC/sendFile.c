#include <stdio.h>
#include "getChecksum.h"
#include "globals.h"

//Send the informations of the encryption in the CryptFile.txt file

int send() {

  const char *path = "/home/indicatic-e1/Desktop/code/CryptageC/CryptFile.txt";
  FILE *file = fopen(path,"w");

  if (file == NULL) {
    printf("Fail during opening CryptInfo.txt\n");
    return 1;
  }


  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      for (int k = 0; k < BITS; k++) {
        fprintf(file, "%d", caesarBlendedXorPayload[i][j][k]);
      }
    }
}

fprintf(file, "\n\n");

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      for (int k = 0; k < BITS; k++) {
        fprintf(file, "%d", caesarBlendedXorInfo[i][j][k]);
      }
    }
  }

fprintf(file, "\n\n");

  fprintf(file, "%d\n",caesarValue);
  fprintf(file, "%d\n",maskValue);

  fclose(file);

  return 0;

}
