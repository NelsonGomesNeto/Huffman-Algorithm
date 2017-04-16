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
  if (argc <= 1)
  {
    printf("Please, enter:\n -c <file-path> to compress\n -d <file-path> to decompress\n -m<c or v> <quantity> <file-path>\n");
    return(1);
  }

  if (argv[1][1] == 'c') // compression
    compress(argv[2]);
  else if (argv[1][1] == 'd') // decompression
    decompress(argv[2]);
  else if (argv[1][1] == 'a') // both
  {
    compress(argv[2]);
    decompress(argv[3]);
  }
  else if (argv[1][1] == 'm') // multiple
  {
    if (argv[1][2] == 'c')
      multipleCompress(argv[2], argv[3]); // Quantity, <file-path>
    else if (argv[1][2] == 'd')
      multipleDecompress(argv[2], argv[3]); // Quantity, <file-path>
  }
  else
    printf("Please, enter:\n -c <file-path> to compress\n -d <file-path> to decompress\n -m<c or v> <quantity> <file-path>\n");

  return(0);
}
