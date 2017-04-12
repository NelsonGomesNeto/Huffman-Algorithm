#include "decompressFile.h"

void decompress(char pathFile[])
{
  FILE *pFile = fopen(pathFile, "rb");
  if (pFile == NULL)
  {
    printf("We weren't able to open the file\n");
    return;
  }
  
  int endOfName = strlen(pathFile);
  int i, j;
  for (i = endOfName; i >= 0 && pathFile[i] != '\\';)
    i --;

  char newFileName[100]; i ++;
  for (j = 0; i < endOfName - 5; j ++, i ++)
    newFileName[j] = pathFile[i];

  FILE *newFile = fopen(newFileName, "wb");

  unsigned char byte;

  int trashSize = 0, treeSize = 0;
  fscanf(pFile, "%c", &byte);
  trashSize = byte >> 5;

  unsigned char mid = (byte << 3);
  treeSize = mid >> 3;
  fscanf(pFile, "%c", &byte);
  treeSize = (treeSize << 8) | byte;

  //printByte(trashSize, 8); printf("\n");
  //printByte(treeSize, 8); printf("\n");
  //printf("Trash Size: %d || Tree Size: %d\n", trashSize, treeSize);

  //printf("Decompressed Tree:\n");
  i = 0;
  huffTree_t *decompressedTree = NULL; createTreeFromPreFix(pFile, &decompressedTree, treeSize, &i);
  //printf("PreOrder: "); printTreePreOrder(decompressedTree); printf("\n");
  //printf("InOrder: "); printTreeInOrder(decompressedTree); printf("\n");
  //printf("PosOrder: "); printTreePosOrder(decompressedTree); printf("\n");
  //printf("Tree Height %d\n", height(decompressedTree));

  decompressBytes(pFile, newFile, decompressedTree, trashSize);
  fclose(pFile);
  fclose(newFile);
}
