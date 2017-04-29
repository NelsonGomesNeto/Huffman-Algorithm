#include "decompressFile.h"

int* getHeader(FILE *pFile)
{
  int *header = (int*) malloc(2 * sizeof(int));
  unsigned char byte;

  int trashSize = 0, treeSize = 0;
  fscanf(pFile, "%c", &byte);
  trashSize = byte >> 5;
  header[0] = trashSize;

  unsigned char mid = (byte << 3);
  treeSize = mid >> 3;
  fscanf(pFile, "%c", &byte);
  treeSize = (treeSize << 8) | byte;
  header[1] = treeSize;

  //  printByte(trashSize, 8); printf("\n");
  //  printByte(treeSize, 8); printf("\n");
  //  printf("Trash Size: %d || Tree Size: %d\n", trashSize, treeSize);

  return(header);
}

void decompress(char pathFile[])
{
  FILE *pFile = fopen(pathFile, "rb");
  if (pFile == NULL)
  {
    printf("We weren't able to open the file\n");
    return;
  }

  long long int *progressBar = createProgressBar(pFile);

  char *decompressedFileName = createDecompressedFileName(pathFile);
  FILE *newFile = fopen(decompressedFileName, "wb");

  int *header = getHeader(pFile);
  int trashSize = header[0];
  int treeSize = header[1];

  //printf("Decompressed Tree:\n");
  int i = 0;
  HuffTree_t *decompressedTree = NULL; createTreeFromPreFix(pFile, &decompressedTree, treeSize, &i);
  if (isHuffTreeEmpty(decompressedTree))
  {
    printf("We weren't able to read the tree properly\n");
    return;
  }
  //printf("PreOrder: "); printTreePreOrder(decompressedTree); printf("\n");
  //printf("InOrder: "); printTreeInOrder(decompressedTree); printf("\n");
  //printf("PosOrder: "); printTreePosOrder(decompressedTree); printf("\n");
  //printf("Tree Height %d\n", height(decompressedTree));

  decompressBytes(pFile, newFile, decompressedTree, trashSize, progressBar);
  printf("Decompressing File.... Done\n");

  free(progressBar);
  free(decompressedFileName);
  free(header);
  destroyHuffTree(decompressedTree);
  fclose(pFile);
  fclose(newFile);
}

void multipleDecompress(char quantityString[], char pathFile[])
{
  int quantity = atoi(quantityString);

  if (quantity <= 1)
    printf("Invalid quantity\n");
  else
  {
    decompress(pathFile);
    fixDecompressExtension(pathFile); // Volta para o arquivo descomprimido para .huff
    updateProgress("Decompressed once.....", ((double) 1 / quantity) * 100, false);

    int i;
    for (i = 0; i < quantity - 1; i ++)
    {
      decompress(pathFile);
      if (i < quantity - 2)
        fixDecompressExtension(pathFile);

      if (i == 0)
        updateProgress("Decompressed twice....", ((double) 2 / quantity) * 100, false);
      else
      {
        char progressString[100];
        sprintf(progressString, "Decompressed %d times..", i + 2);
        updateProgress(progressString, ((double) (i + 2) / quantity) * 100, false);
      }
    }

    printf("You've decompressed %d times\n", quantity);
  }
}

char* createDecompressedFileName(char pathFile[])
{
  int endOfName = strlen(pathFile);
  int i, j;
  for (i = endOfName; i >= 0 && pathFile[i] != '\\';)
    i --;

  char *newFileName = (char*) malloc(100 * sizeof(char)); i ++;
  for (j = 0; i < endOfName - 5; j ++, i ++)
    newFileName[j] = pathFile[i];

  newFileName[j] = '\0';

  return(newFileName);
}

void fixDecompressExtension(char pathFile[])
{
  char *originalName = (char*) malloc(100 * sizeof(char));
  strcpy(originalName, pathFile);

  int endOfName = strlen(pathFile);
  int i = endOfName, j;
  j = 5; char dotHuff[6] = {'.', 'h', 'u', 'f', 'f', '\0'};
  while (i >= 0 && pathFile[i] == dotHuff[j])
  {
    i --; j --;
    if (j == -1)
      j = 4;
  }

  pathFile[i + 1] = '\0';

  if (strcmp(originalName, pathFile) != 0)
    remove(originalName);

  rename(pathFile, originalName);

  strcpy(pathFile, originalName);
}
