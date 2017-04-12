#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "compressFile.h"
#include "decompressFile.h"

int main(int argc, char **argv)
{
  //printf("%c %s\n", argv[1][0], argv[2]);
  // COMPRESSÃO!!!!
  if (argv[1][0] == 'c')
    compress(argv[2]);
  else if (argv[1][0] == 'd')
    decompress(argv[2]);
  else if (argv[1][0] == 'a')
  {
    compress(argv[2]);
    decompress(argv[3]);
  }
  else
    printf("Please, enter:\n c <file-path> to compress\nd <file-path> to decompress\n");
  return(0);
}
