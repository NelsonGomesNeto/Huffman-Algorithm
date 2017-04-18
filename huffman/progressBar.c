#include "progressBar.h"

void updateProgress(char string[], int porcentage, bool cleaning)
{
  printf("\r");
  printf("%s%3d%% [", string, porcentage);

  int x;
  int c = porcentage / 10;
  for (x=0; x<c; x++)
    printf("#");
  for (x=c; x<10; x++)
    printf(" ");

  if (cleaning)
    printf("]\n\033[F\033[J");
  else
    printf("]\n\n");
}

long long int* createProgressBar(FILE *pFile)
{
  fseek(pFile, 0, SEEK_END);
  long double fileSize = ftell(pFile);
  rewind(pFile);
  long long int *porcentageBar = (long long int*) malloc(100 * sizeof(long long int)), fill;
  for (fill = 0; fill < 100; fill ++)
    porcentageBar[fill] = ((double) fill / 100) * fileSize;

  return(porcentageBar);
}
