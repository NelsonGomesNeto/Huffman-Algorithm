#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <inttypes.h>
#include "huffTree.h"
#include "list.h"

int main()
{
  unsigned char bytes;
  FILE *pFile, *newFile;
  pFile = fopen("textoIn.txt", "rb");
  newFile = fopen("textoOut.txt", "wb");

  if (pFile == NULL)
  {
    printf("We weren't able to find this file!\n");
    return(1);
  }

  long long int freq[256]; int i;
  for (i = 0; i < 256; i ++)
    freq[i] = 0;

  long long int soma = 0;
  while (fscanf(pFile, "%c", &bytes) != EOF)
  {
    fprintf(newFile, "%c", bytes);
    freq[bytes] ++; soma ++; // contagem de char no lugar certo!
  }

  printf("It's fine until here\n"); fflush(stdout);

  list_t *list = listFromArray(freq);

  sortList(list);

  printList(list);

  printf("Compressed Tree:\n");
  huffTree_t *compressedTree = createTreeFromList(list);
  printf("PreOrder: "); printTreePreOrder(compressedTree); printf("\n");
  printf("InOrder: "); printTreeInOrder(compressedTree); printf("\n");
  printf("PosOrder: "); printTreePosOrder(compressedTree); printf("\n");

  printf("Total de Bytes: %lld\n", soma);

  int sizeOfTree; scanf("%d", &sizeOfTree); i = 0;
  getchar();
  printf("Decompressed Tree:\n");
  huffTree_t *decompressedTree = NULL; createTreeFromPreFix(&decompressedTree, sizeOfTree, &i);
  printf("PreOrder: "); printTreePreOrder(decompressedTree); printf("\n");
  printf("InOrder: "); printTreeInOrder(decompressedTree); printf("\n");
  printf("PosOrder: "); printTreePosOrder(decompressedTree); printf("\n");

	long long int dictionary[256][10];
	for(i = 0; i < 256; i++)
	{
		dictionary[i][0] = -1;
	}
	int bits[8];
	createDictionary(compressedTree, dictionary, bits, 0);
	int j;

	for(i = 0; i < 256; i++)
	{
		for(j = 0; j < 8 && dictionary[i][j] != -1; j++)
		{
			printf("%lld", dictionary[i][j]);
		}
		if(dictionary[i][0] != -1)
		printf(" tam = %lld freq = %lld\n", dictionary[i][8],  dictionary[i][9]);
	}

	long long int trashSize = 0;
	countTrashSize(dictionary, &trashSize);
	printf("trash size = %lld", trashSize);
  return(0);
}
