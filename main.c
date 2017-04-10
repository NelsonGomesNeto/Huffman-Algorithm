#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "huffTree.h"
#include "list.h"
#include "fileSetup.h"
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
      printf("Compressed Tree:\n");
      huffTree_t *compressedTree = createTreeFromFile();
      printf("PreOrder: "); printTreePreOrder(compressedTree); printf("\n");
      printf("InOrder: "); printTreeInOrder(compressedTree); printf("\n");
      printf("PosOrder: "); printTreePosOrder(compressedTree); printf("\n");

      unsigned int dictionary[256][2];
      long long int frequency[256]; int i;
      for(i = 0; i < 256; i ++)
        frequency[i] = -1;

      unsigned int zero = 0;
      createDictionary(compressedTree, dictionary, frequency, zero, 0);

      for(i = 0; i < 256; i++)
      {
        if(frequency[i] != -1)
        {
          //printf("%d", dictionary[i][0]);
          printByte(dictionary[i][0], 13);
          printf(" tam = %d freq = %lld char = %c\n", dictionary[i][1],  frequency[i], i);
        }
      }

      int trashSize = countTrashSize(dictionary, frequency);
      int treeSize = countTreeSize(compressedTree);
      printf("Trash Size: %d || Tree Size: %d\n", trashSize, treeSize);

      unsigned char *header = createHeader(trashSize, treeSize, compressedTree);

      FILE *pFile = fopen("textoIn.txt", "rb");
      compressFile(pFile, header, dictionary, compressedTree);
      fclose(pFile);
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
