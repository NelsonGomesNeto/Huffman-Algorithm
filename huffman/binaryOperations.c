#include <stdio.h>
#include <stdbool.h>

unsigned int setBit(unsigned int byte, int i)
{
  unsigned int mask = 1 << i;
  return(mask | byte);
}

bool isBitiSet(unsigned int byte, int i)
{
  unsigned int mask = 1 << i;
  return(mask & byte);
}

void printByte(unsigned char byte)
{
  int i;
  for (i = 7; i >= 0; i --)
    printf("%d", isBitiSet(byte, i));

  //printf("\n");
}
