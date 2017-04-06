#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
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

  int freq[256], i;
  for (i = 0; i < 256; i ++)
    freq[i] = 0;

  int soma = 0;
  while (fscanf(pFile, "%c", &bytes) != EOF)
  {
    fprintf(newFile, "%c", bytes);
    freq[bytes] ++; soma ++; // contagem de char no lugar certo!
  }

  printf("It's fine until here\n"); fflush(stdout);

  list_t *list = listFromArray(freq);

  sortList(list);

  printList(list);

  printf("Total de Bytes: %d\n", soma);

  return(0);
}
