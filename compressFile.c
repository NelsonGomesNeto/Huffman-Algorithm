#include "compressFile.h"

unsigned char* createHeader(int trashSize, int treeSize)
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
  printf("Creating Tree.........");
    huffTree_t *compressedTree = createTreeFromFile(pathFile);
    if (isHuffTreeEmpty(compressedTree))
      return;
  printf("Creating Tree......... Done\n");
  //printf("Compressed Tree:\n");
  //printf("PreOrder: "); printTreePreOrder(compressedTree); printf("\n");

  printf("Creating Dictionary...");
    bool dictionary[256][256]; int bitsQuantity[256];
    long long int frequency[256]; int i;
    for(i = 0; i < 256; i ++)
      frequency[i] = -1;

    bool bits[256];
    createDictionary(compressedTree, dictionary, bitsQuantity, frequency, bits, 0);
  printf(" Done\n");

  printf("Creating Header.......");
    int trashSize = countTrashSize(bitsQuantity, frequency);
    int treeSize = countTreeSize(compressedTree);
    //printf("Trash Size: %d || Tree Size: %d\n", trashSize, treeSize);
    unsigned char *header = createHeader(trashSize, treeSize);
  printf(" Done\n");

  printf("Compressing File......");
    compressFile(pathFile, header, dictionary, bitsQuantity, compressedTree);
  printf("Compressing File...... Done\n");

  free(header);
  destroyHuffTree(compressedTree);
}

void multipleCompress(char quantityString[], char pathFile[])
{
  int quantity = atoi(quantityString);
  
  if (quantity <= 0)
    printf("Invalid quantity\n");
  else
  {
    int i;
    compress(pathFile);
    printf("Compressed once\n\n");
    strcat(pathFile, ".huff");

    for (i = 0; i < quantity - 1; i ++)
    {
      compress(pathFile);
      if (i == 0)
        printf("Compressed twice\n\n");
      else
        printf("Compressed %d times\n\n", i + 2);
    }

    printf("You've compressed %d times\n", quantity);
  }
}

void compressFile(char pathFile[], unsigned char *header, bool dictionary[][256], int bitsQuantity[], huffTree_t *tree)
{
  FILE *pFile = fopen(pathFile, "rb");
  long long int *progressBar = createProgressBar(pFile);

  char *compressedFileName = createCompressedFileName(pathFile);

  FILE *newFile = fopen(compressedFileName, "wb");
  fprintf(newFile, "%c%c", header[0], header[1]);
  printTreeInFile(newFile, tree);

  long long int progress = 0; int atual = 0;
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

        newByte = 0;
      }
    }
    if (progressBar[atual] == progress)
      updateProgress("Compressing File......\0", atual ++);

    progress ++;
  }

  if (header[0] >> 5 != 0) // Se o trashSize for diferente de zero
    fprintf(newFile, "%c", newByte);

  free(progressBar);
  fclose(newFile);
  fclose(pFile);
  fixExtension(compressedFileName);
  free(compressedFileName);
}

char* createCompressedFileName(char pathFile[])
{
  int endOfName = strlen(pathFile);
  int i, j;
  for (i = endOfName; i >= 0 && pathFile[i] != '\\';)
    i --;

  i ++;
  char *newFileName = (char*) malloc(100 * sizeof(char));
  for (j = 0; i < endOfName; j ++, i ++)
    newFileName[j] = pathFile[i];

  newFileName[j] = '\0';
  strcat(newFileName, ".huff");

  return(newFileName);
}

void fixExtension(char pathFile[])
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
  strcat(pathFile, ".huff");

  if (strcmp(originalName, pathFile) != 0)
    remove(pathFile);

  if (rename(originalName, pathFile))
    printf("Success\n");
}
