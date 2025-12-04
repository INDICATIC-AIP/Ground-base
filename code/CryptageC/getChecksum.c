#include <stdio.h>
#include <string.h>
#include "globals.h"

//Get the checksum payload and info from StringCrypt.txt file

void checksum(char *payload, char *info) {

  char checksumPayload[COLS];
  char checksumInfo[COLS];
  int i = 0;

  FILE *file;
  const char *path = "/home/indicatic-e1/Desktop/code/infoIMG/StringCrypt.txt";

  file = fopen(path, "r");

  if (file == NULL) {
      perror("Cannot open the file\n");
  } else {
      printf("Filed opened\n");

      //Put the two checksun in buffer
      char buffer[256];
      while (fgets(buffer, sizeof(buffer), file) != NULL) {
          printf("%s", buffer);
      }

    //cancel '\n' and replace it with EOF
    int len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    //Find the first space to have the
  while (buffer[i] != ' ' && buffer[i] != '\0') {
    checksumPayload[i] = buffer[i];
    i++;
  }
  checksumPayload[i] = '\0';

  //checksun info
  i++; //Skip the space
  int j = 0;
  while (buffer[i] != '\0') {
    checksumInfo[j] = buffer[i];
    i++;
    j++;
  }
  checksumInfo[j] = '\0';

  strcpy(payload, checksumPayload);
  strcpy(info, checksumInfo);

  fclose(file);
  }
}
