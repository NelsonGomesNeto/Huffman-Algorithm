#include "progressBar.h"

void updateProgress(char string[], double porcentage)
{
  printf("\r");
  printf("%s%3d%% [", string, (int) porcentage);

  int x;
  int c = porcentage / 10;
  for (x=0; x<c; x++)
    printf("#");
  for (x=c; x<10; x++)
    printf(" ");

  printf("]\n\033[F\033[J");
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
