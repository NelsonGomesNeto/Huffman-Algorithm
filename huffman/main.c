#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "huffTree.h"
#include "list.h"
#include "compressFile.h"

int main()
{
  // COMPRESSÃO!!!!
  char type;
  while (scanf("%c", &type) && type != 'z')
  {
    getchar();
    if (type == 'c')
    {
      compress();
    }


    //DESCOMPRESSÃO!!!!

    if (type == 'd')
    {
      FILE *pFile = fopen("textoOut.txt", "rb");
      if (pFile == NULL)
      {
        printf("We weren't able to open the file\n");
        return(1);
      }
      FILE *newFile = fopen("decompressed.txt", "wb");

      unsigned char byte;

      int trashSize = 0, treeSize = 0;
      fscanf(pFile, "%c", &byte);
      trashSize = byte >> 5;

      unsigned char mid = (byte << 3);
      treeSize = mid >> 3;
      fscanf(pFile, "%c", &byte);
      treeSize = (treeSize << 8) | byte;

      printByte(trashSize, 8); printf("\n");
      printByte(treeSize, 8); printf("\n");
      printf("Trash Size: %d || Tree Size: %d\n", trashSize, treeSize);

      printf("Decompressed Tree:\n"); int i = 0;
      huffTree_t *decompressedTree = NULL; createTreeFromPreFix(pFile, &decompressedTree, treeSize, &i);
      printf("PreOrder: "); printTreePreOrder(decompressedTree); printf("\n");
      printf("InOrder: "); printTreeInOrder(decompressedTree); printf("\n");
      printf("PosOrder: "); printTreePosOrder(decompressedTree); printf("\n");
      printf("Tree Height %d\n", height(decompressedTree));

      decompressBytes(pFile, newFile, decompressedTree, trashSize);
      fclose(pFile);
      fclose(newFile);
    }
  }

  return(0);
}
