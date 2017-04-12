#include "compressFile.h"

unsigned char* createHeader(int trashSize, int treeSize, huffTree_t *tree)
{
  unsigned char *bytes = (unsigned char*) malloc(3 * sizeof(unsigned char));
  bytes[0] = trashSize << 5 | treeSize >> 8;
  bytes[1] = treeSize;

  //printf("Header: %c%c", bytes[0], bytes[1]);
  //printTreePreOrder(tree); printf("\n");
  return(bytes);
}

void compress(char pathFile[])
{
  huffTree_t *compressedTree = createTreeFromFile(pathFile);
  if (isHuffTreeEmpty(compressedTree))
    return;

  //printf("Compressed Tree:\n");
  //printf("PreOrder: "); printTreePreOrder(compressedTree); printf("\n");

  bool dictionary[256][256]; int bitsQuantity[256];
  long long int frequency[256]; int i;
  for(i = 0; i < 256; i ++)
    frequency[i] = -1;

  bool bits[256];
  createDictionary(compressedTree, dictionary, bitsQuantity, frequency, bits, 0);
  updateProgress(30);

  int trashSize = countTrashSize(bitsQuantity, frequency);
  int treeSize = countTreeSize(compressedTree);
  //printf("Trash Size: %d || Tree Size: %d\n", trashSize, treeSize);

  unsigned char *header = createHeader(trashSize, treeSize, compressedTree);

  compressFile(pathFile, header, dictionary, bitsQuantity, compressedTree);
  updateProgress(100);
}

void compressFile(char pathFile[], unsigned char *header, bool dictionary[][256], int bitsQuantity[], huffTree_t *tree)
{
  FILE *pFile = fopen(pathFile, "rb");
  fseek(pFile, 0, SEEK_END);
  long long int fileSize = ftell(pFile);
  rewind(pFile);

  int endOfName = strlen(pathFile);
  int i, j;
  for (i = endOfName; i >= 0 && pathFile[i] != '\\';)
    i --;

  char newFileName[1000]; i ++;
  for (j = 0; i < endOfName; j ++, i ++)
    newFileName[j] = pathFile[i];

  newFileName[j] = '\0';

  strcat(newFileName, ".huff");

  FILE *newFile = fopen(newFileName, "wb");
  fprintf(newFile, "%c%c", header[0], header[1]);
  printTreeInFile(newFile, tree);

  long long int progress = 0; int atual = 20;
  unsigned char byte = 0, newByte = 0; int pos = 0;
  while (fscanf(pFile, "%c", &byte) != EOF)
  {
    int i;
    for (i = 0; i < bitsQuantity[byte]; i ++, pos ++)
    {
      pos %= 8;
      if (dictionary[byte][i])
        newByte = setBit(newByte, 7 - pos);

      if ((pos + 1) % 8 == 0)
      {
        fprintf(newFile, "%c", newByte);
        if (progress / fileSize > atual)
          updateProgress(atual ++);
          
        newByte = 0;
      }
    }
    progress ++;
  }

  if (header[0] >> 5 != 0) // Se o trashSize for diferente de zero
    fprintf(newFile, "%c", newByte);

  //printf("\n");
  fclose(newFile);
  fclose(pFile);
  updateProgress(0);
}
