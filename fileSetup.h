#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <inttypes.h>
#include "huffTree.h"
#include "list.h"
#ifndef FILESETUP_H
#define FILESETUP_H

huffTree_t* createTreeFromFile()
{
  FILE *pFile, *newFile;
  pFile = fopen("textoIn.txt", "rb");
  newFile = fopen("textoOut.txt", "wb");

  if (pFile == NULL)
  {
    printf("We weren't able to find this file!\n");
    return(NULL);
  }

  long long freq[256]; int i;
  for (i = 0; i < 256; i ++)
    freq[i] = 0;

  unsigned char bytes;
  long long int soma = 0;
  while (fscanf(pFile, "%c", &bytes) != EOF)
  {
    fprintf(newFile, "%c", bytes);
    freq[bytes] ++; soma ++; // contagem de char no lugar certo!
  }

  fclose(pFile);
  fclose(newFile);

  printf("It's fine until here\n"); fflush(stdout);

  list_t *list = listFromArray(freq);

  sortList(list);

  printList(list);

  printf("Total de Bytes: %lld\n", soma);

  printf("Compressed Tree:\n");
  huffTree_t *compressedTree = createTreeFromList(list);

  return(compressedTree);
}

#endif //FILESETUP_H
