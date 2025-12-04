#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "difffunction.h"
#include "global.h"

//Here is the main of the decryption, where each functions to realise it are called

//variables declaration
char BitPayload[ROWS][COLS][BITS];
char BitInfo[ROWS][COLS][BITS];
char CaesarValue[12];
int CaesarValueint = 0;
char Mask[BITS];
unsigned char maskBits[BITS];

char BitPayloadUnxor[ROWS][COLS][BITS];
char BitInfoUnxor[ROWS][COLS][BITS];

int BinaryUnxoredToDecimalPayload[ROWS][COLS];
int BinaryUnxoredToDecimalInfo[ROWS][COLS];

int ShamirPartsPayload[ROWS][COLS];
int ShamirPartsInfo[ROWS][COLS];

char PayloadHash[COLS];

int main() {

//Secret shamir variables
int n = 8;
int threshold = n/4;

//Files that contains the encryption informations
const char *pathPayload = "/var/services/homes/INDICATIC/InteroperabilityCode/tmpFile/BitPayload.txt";
const char *pathInfo = "/var/services/homes/INDICATIC/InteroperabilityCode/tmpFile/BitInfo.txt";
const char *pathCaesar = "/var/services/homes/INDICATIC/InteroperabilityCode/tmpFile/Caesar.txt";
const char *pathMask = "/var/services/homes/INDICATIC/InteroperabilityCode/tmpFile/Mask.txt";
//executive path python code to get shamirs parts
const char *command = "python3 /var/services/homes/INDICATIC/InteroperabilityCode/shamirs.py";

//Call the functions to put each informations files in their due variables
FileToMultiTab(pathPayload, BitPayload, sizeof(BitPayload));
FileToMultiTab(pathInfo, BitInfo, sizeof(BitInfo));
FileToTab(pathCaesar, CaesarValue, sizeof(CaesarValue));
FileToTab(pathMask, Mask, sizeof(Mask));

//Print the variables to ensure their values
printBinary();
//printf("CaesarValue : %s\n",CaesarValue );
//printf("BitMask : %s\n",Mask );

//Convert the Mask value into binary
binaryMask(Mask, maskBits);

//First step of decryption, xor the payload and info binary received
unxor(BitPayloadUnxor,BitPayload, maskBits);
unxor(BitInfoUnxor,BitInfo, maskBits);

//Print the unxor obtained
//printBinaryUnxor();

//Convert the binary into decimal
binaryToDecimal(BitPayloadUnxor, BinaryUnxoredToDecimalPayload);
binaryToDecimal(BitInfoUnxor, BinaryUnxoredToDecimalInfo);

//Print the decimal obtained
printTabDecimal(BinaryUnxoredToDecimalPayload, "Payload decimal after unxored ↓");
printTabDecimal(BinaryUnxoredToDecimalInfo, "Info decimal after unxored ↓");

//Convert CaesarValue into interger to be used in the decryptCaesar function
CaesarValueint = atoi(CaesarValue);

//Using the inverse of caesar code
decryptCaesar(ShamirPartsPayload,BinaryUnxoredToDecimalPayload,CaesarValueint);
decryptCaesar(ShamirPartsInfo,BinaryUnxoredToDecimalInfo,CaesarValueint);

//Print the decimal obtained after uncaesar function used
//printTabDecimal(ShamirPartsPayload, "Payload decimal after caesar ↓");
//printTabDecimal(ShamirPartsInfo, "Info decimal after caesar ↓");

//print the shamirs parts in characters
printTabShamirsParts(ShamirPartsPayload, "Payload shamirs parts");
printTabShamirsParts(ShamirPartsInfo, "Info shamirs parts");

send();
system(command);

  return 0;
}
