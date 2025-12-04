#include <stdio.h>
#include "difffunction.h"
#include "global.h"

//Send the differents parts of shamirs, info and payload, so that the code shamirs.py can refund the hash

int send() {

  //File where python will take the shamirs parts to apply with lagrange interpolation
  const char *path = "/var/services/homes/INDICATIC/InteroperabilityCode/ShamirsParts.txt"; //File sent
  FILE *file = fopen(path,"w");

  if (file == NULL) {
    printf("Fail during opening ShamirsParts.txt\n");
    return 1;
  }

fprintf(file, "[");
  for (int i = 0; i < ROWS; i++) {
    fprintf(file,"\"");
    fprintf(file, "%d-",i+1 );
    for (int j = 0; j < COLS; j++) {
      fprintf(file, "%c",ShamirPartsPayload[i][j]);
    }
    printf("i : %d\n",i );
    if (i != 7) {
      fprintf(file,"\"");
      fprintf(file, ", ");
    } else if (i == 7) {
      fprintf(file, "\"]");
    }
}

fprintf(file, "\n");

fprintf(file, "[");
  for (int i = 0; i < ROWS; i++) {
    fprintf(file,"\"");
    fprintf(file, "%d-",i+1 );
    for (int j = 0; j < COLS; j++) {
      fprintf(file, "%c",ShamirPartsInfo[i][j]);
    }
    if (i != 7) {
      fprintf(file,"\"");
      fprintf(file, ", ");
    } else if (i == 7) {
      fprintf(file, "\"]");
    }
}

  fclose(file);

  return 0;

}
