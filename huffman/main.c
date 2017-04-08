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
  printf("Compressed Tree:\n");
  huffTree_t *compressedTree = createTreeFromFile();
  printf("PreOrder: "); printTreePreOrder(compressedTree); printf("\n");
  printf("InOrder: "); printTreeInOrder(compressedTree); printf("\n");
  printf("PosOrder: "); printTreePosOrder(compressedTree); printf("\n");

  unsigned char dictionary[256][2];
  long long int frequency[256]; int i;
	for(i = 0; i < 256; i ++)
	  frequency[i] = -1;

	createDictionary(compressedTree, dictionary, frequency, 0, 0);

	for(i = 0; i < 256; i++)
	{
		if(frequency[i] != -1)
    {
      //printf("%d", dictionary[i][0]);
      printByte(dictionary[i][0]);
      printf(" tam = %d freq = %lld\n", dictionary[i][1],  frequency[i]);
    }
	}

	int trashSize = countTrashSize(dictionary, frequency);
  int treeSize = countTreeSize(compressedTree);
	printf("Trash Size: %d || Tree Size: %d\n", trashSize, treeSize);

  unsigned char *header = createHeader(trashSize, treeSize, compressedTree);

  FILE *pFile = fopen("textoIn.txt", "rb");
  compressFile(pFile, header, dictionary, compressedTree);
  fclose(pFile);




  int sizeOfTree; scanf("%d", &sizeOfTree); i = 0;
  getchar();
  printf("Decompressed Tree:\n");
  huffTree_t *decompressedTree = NULL; createTreeFromPreFix(&decompressedTree, sizeOfTree, &i);
  printf("PreOrder: "); printTreePreOrder(decompressedTree); printf("\n");
  printf("InOrder: "); printTreeInOrder(decompressedTree); printf("\n");
  printf("PosOrder: "); printTreePosOrder(decompressedTree); printf("\n");

  return(0);
}
