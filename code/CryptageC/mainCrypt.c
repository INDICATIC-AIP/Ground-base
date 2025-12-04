#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "getChecksum.h"
#include "stepOne.h"
#include "globals.h"

//Here each functions are called to realise the encryption

//Shamir parts of payload and info
int shamirpartsPayload[ROWS][COLS];
int shamirpartsInfo[ROWS][COLS];

//Shamir combined with ceasar code
int shamirBlendedCaesarPayload[ROWS][COLS];
int shamirBlendedCaesarInfo[ROWS][COLS];

//Ceasar code changed into binary
int ceasarBinaryPayload[ROWS][COLS][BITS];
int ceasarBinaryInfo[ROWS][COLS][BITS];

//Binary of ceasar combined with xor
int caesarBlendedXorPayload[ROWS][COLS][BITS];
int caesarBlendedXorInfo[ROWS][COLS][BITS];

//Variables for ceasar code, mask that's applied with binary, maskBits is the binary value of maskValue
unsigned short caesarValue;
unsigned char maskValue;
unsigned char maskBits[BITS];

int main() {

  //Initialize the random number generator
  srand(time(NULL));

  //Assign a random value between 100 and 900 that's applied with ceasar step
  caesarValue = (rand() %900 ) + 100;

  //Assign a random mask number value that's applied with xor step
  maskValue = (rand() %255 ) + 1;

  //Declaration where to put the checksum of payload and info
  char Payload[COLS];
  char Info[COLS];

  //Secret shamir variables
  char n = 8;
  char threshold = n/4;
  char makekey[2][COLS];

  //Print the value of ceasar and mask
  //printf("Mask value : %d \n",maskValue);
  //printf(" caesarValue : %d\n",caesarValue);

  //execute python code to create shamirs parts
  const char *command = "python3 /home/indicatic-e1/Desktop/code/CryptageC/ShamirsParts.py";

    // Exécuter le fichier Python
    int result = system(command);

  //########################FIRST encryption part#################################
  //First step of the encryption is to use shamir and put each part in their respective tabs
  shamirParts(shamirpartsPayload,"/home/indicatic-e1/Desktop/code/CryptageC/shamirPartsPayload.txt");
  shamirParts(shamirpartsInfo,"/home/indicatic-e1/Desktop/code/CryptageC/shamirPartsInfo.txt");

  //Print the tabs of the shamir parts of payload and info
  //printTab();

  //########################SECOND encryption part ###############################
  //Apply ceasar code to each shamir parts
  caesar(shamirBlendedCaesarPayload,shamirpartsPayload,caesarValue);
  caesar(shamirBlendedCaesarInfo,shamirpartsInfo,caesarValue);

  //Print the tabs after ceasar code applied
  //printTabCaesar();

  //Convert tabs in binary
  decToBinary(ceasarBinaryPayload,shamirBlendedCaesarPayload);
  decToBinary(ceasarBinaryInfo,shamirBlendedCaesarInfo);

  //Print the tabs after ceasar binary
  //printBinary();

  //########################THIRD encryption part ################################
  //Apply xor to ceasar code
  binaryMask(maskValue, maskBits);

  //Apply xor the each bits with the mask value
  xor(caesarBlendedXorPayload, ceasarBinaryPayload, maskBits);
  xor(caesarBlendedXorInfo, ceasarBinaryInfo, maskBits);

  //Print the tabs after xor applied
  //printBinaryWithMask();

  //#######################Send file with bits###################################
  //Send the payload and info file crypted with the mask and the ceasar value
  send();

  return 0;
}
