#include "huffTree.h"
#include "list.h"
#include "binaryOperations.h"

struct _huffTree
{
  unsigned char byte;
  long long int frequency;
  huffTree_t *next;
  huffTree_t *left;
  huffTree_t *right;
};

huffTree_t* createNode(unsigned char byte, long long int frequency)
{
  huffTree_t *temp = (huffTree_t*) malloc(1 * sizeof(huffTree_t));
  temp->byte = byte;
  temp->frequency = frequency;
  temp->next = NULL;
  temp->left = NULL;
  temp->right = NULL;
  return(temp);
}

huffTree_t* createTree(unsigned char byte, long long int frequency, huffTree_t *left, huffTree_t *right)
{
  huffTree_t *temp = (huffTree_t*) malloc(1 * sizeof(huffTree_t));
  temp->byte = byte;
  temp->frequency = frequency;

  temp->next = NULL;

  temp->left = left;
  if (left != NULL)
    left->next = NULL;

  temp->right = right;
  if (right != NULL)
    right->next = NULL;

  return(temp);
}

void createTreeFromPreFix(FILE *pFile, huffTree_t **newTree, int end, int *i)
{
  if ((*i) == end) return;

  unsigned char expression;
  if (fscanf(pFile, "%c", &expression) && expression == '*')
  {
    (*newTree) = createNode('*', 0);
    (*i) ++; createTreeFromPreFix(pFile, &(*newTree)->left, end, &*i);
    (*i) ++; createTreeFromPreFix(pFile, &(*newTree)->right, end, &*i);
  }
  else
  {
    if (expression == 92)
    {
      int aux = expression;
      fscanf(pFile, "%c", &expression);
      if (expression == '*' || expression == 92)
        (*newTree) = createNode(expression, 0);
      else
        (*newTree) = createNode(aux, 0);
    }
    else
      (*newTree) = createNode(expression, 0);
  }
}

huffTree_t* createTreeFromFile()
{
  FILE *pFile;
  pFile = fopen("textoIn.txt", "rb");

  if (pFile == NULL)
  {
    printf("We weren't able to find this file!\n");
    return(NULL);
  }

  long long int freq[256]; int i;
  for (i = 0; i < 256; i ++)
    freq[i] = 0;

  unsigned char bytes;
  long long int soma = 0;
  while (fscanf(pFile, "%c", &bytes) != EOF)
  {
    //fprintf(newFile, "%c", bytes);
    freq[bytes] ++; soma ++; // contagem de char no lugar certo!
  }

  if (soma == 0)
  {
    printf("This file is too god-like, it's so damn compressed that it's better to leave the way it is\n");
    return(NULL);
  }

  fclose(pFile);

  printf("It's fine until here\n"); fflush(stdout);

  list_t *list = listFromArray(freq);

  sortList(list);

  printList(list);

  printf("Total de Bytes: %lld\n", soma);

  printf("Compressed Tree:\n");
  huffTree_t *compressedTree = createTreeFromList(list);

  return(compressedTree);
}

bool isHuffTreeEmpty(huffTree_t *hm)
{
  return(hm == NULL);
}

int max(int a, int b)
{
  return(a > b ? a : b);
}

int height(huffTree_t *avl)
{
  if (isHuffTreeEmpty(avl)) return(-1);

  return(1 + max(height(avl->left), height(avl->right)));
}


bool isMoreFrequent(huffTree_t *a, huffTree_t *b)
{
  return(a->frequency > b->frequency);
}

void swap(huffTree_t *a, huffTree_t *b)
{
  huffTree_t *aux = (huffTree_t*) malloc(1 * sizeof(huffTree_t));
  aux->byte = a->byte;
  a->byte = b->byte;
  b->byte = aux->byte;

  aux->frequency = a->frequency;
  a->frequency = b->frequency;
  b->frequency = aux->frequency;
}

void addNext(huffTree_t *atual, huffTree_t *prox)
{
  atual->next = prox;
}

huffTree_t* getNext(huffTree_t *atual)
{
  if (isHuffTreeEmpty(atual)) return(NULL);

  return(atual->next);
}

void setNext(huffTree_t *atual, huffTree_t *next)
{
  if (isHuffTreeEmpty(atual)) return;

  atual->next = next;
}

long long int getFrequency(huffTree_t *atual)
{
  if (isHuffTreeEmpty(atual)) return(INT_MIN);

  return(atual->frequency);
}

void printNode(huffTree_t *atual)
{
  if (isHuffTreeEmpty(atual)) return;

  printf("Letra: %c || Frequencia: %lld\n", atual->byte, atual->frequency);
}

void printTreePreOrder(huffTree_t *tree)
{
  if (!isHuffTreeEmpty(tree))
  {
    if (isHuffTreeEmpty(tree->left) && isHuffTreeEmpty(tree->right) && (tree->byte == '*' || tree->byte == 92))
      printf("%c", 92);

    printf("%c", tree->byte);
    printTreePreOrder(tree->left);
    printTreePreOrder(tree->right);
  }
}

void printTreeInFile(FILE *newFile, huffTree_t *tree)
{
  if (!isHuffTreeEmpty(tree))
  {
    if (isHuffTreeEmpty(tree->left) && isHuffTreeEmpty(tree->right) && (tree->byte == '*' || tree->byte == 92))
      fprintf(newFile, "%c", 92);

    fprintf(newFile, "%c", tree->byte);
    printTreeInFile(newFile, tree->left);
    printTreeInFile(newFile, tree->right);
  }
}

void printTreeInOrder(huffTree_t *tree)
{
  if (!isHuffTreeEmpty(tree))
  {
    printTreeInOrder(tree->left);
    if (isHuffTreeEmpty(tree->left) && isHuffTreeEmpty(tree->right) && (tree->byte == '*' || tree->byte == 92))
      printf("%c", 92);

    printf("%c", tree->byte);
    printTreeInOrder(tree->right);
  }
}

void printTreePosOrder(huffTree_t *tree)
{
  if (!isHuffTreeEmpty(tree))
  {
    printTreePosOrder(tree->left);
    printTreePosOrder(tree->right);
    if (isHuffTreeEmpty(tree->left) && isHuffTreeEmpty(tree->right) && (tree->byte == '*' || tree->byte == 92))
      printf("%c", 92);

    printf("%c", tree->byte);
  }
}

void createDictionary(huffTree_t *tree, bool dictionary[][256], int bitsQuantity[], long long int frequency[], bool bits[], int depth)
{
	if(!isHuffTreeEmpty(tree))
	{
		if (isHuffTreeEmpty(tree->left) && isHuffTreeEmpty(tree->right))
		{
      int i;
      for (i = 0; i < depth; i ++)
        dictionary[tree->byte][i] = bits[i];

      bitsQuantity[tree->byte] = depth;
      frequency[tree->byte] = tree->frequency;
			//dictionary[tree->byte][0] = byte >> (13 - depth);
      //printByte(dictionary[tree->byte][0], 13); printf(" %c\n", tree->byte);
			//printf("[%c]", tree->byte);
		}
		else
		{
			bits[depth] = 0;
			createDictionary(tree->left, dictionary, bitsQuantity, frequency, bits, depth + 1);
			bits[depth] = 1; //byte = setBit(byte, (12 - depth));
      //printf("~~~"); printByte(byte); printf("# %d\n", byte);
			createDictionary(tree->right, dictionary, bitsQuantity, frequency, bits, depth + 1);
		}
	}
}

int countTrashSize(int bitsQuantity[], long long int frequency[])
{
	int i; long long int trashSize = 0;
	for(i = 0; i < 256; i ++)
		if(frequency[i] != -1)
			trashSize += (bitsQuantity[i] * frequency[i]) % 8;

	trashSize = 8 - (trashSize % 8);
  return(trashSize);
}

int countTreeSize(huffTree_t *tree)
{
  int sum = 0;
  if (!isHuffTreeEmpty(tree))
  {
    if (isHuffTreeEmpty(tree->left) && isHuffTreeEmpty(tree->right) && (tree->byte == '*' || tree->byte == 92))
      sum = 1;

    sum += 1 + countTreeSize(tree->left);
    sum += countTreeSize(tree->right);
  }
  return(sum);
}

void decompressBytes(FILE *pFile, FILE *newFile, huffTree_t *tree, int trashSize)
{
  unsigned char stringToPrint[10], byte; int done = 0, i, j;
  huffTree_t *curr = tree, *save;
  while (fscanf(pFile, "%c", &byte) != EOF)
  {
    save = curr;
    for (j = 0; j < done; j ++)
      fprintf(newFile, "%c", stringToPrint[j]);

    for (i = 7, done = 0; i >= 0; i --)
    {
      if (isBitiSet(byte, i))
        curr = curr->right;
      else
        curr = curr->left;

      if (isHuffTreeEmpty(curr->left) && isHuffTreeEmpty(curr->right))
      {
        stringToPrint[done ++] = curr->byte;
        curr = tree;
      }
    }
    //printByte(byte); printf(" ");
  } //printf("\n");

  curr = save;
  for (i = 7, done = 0; i >= trashSize; i --)
  {
    if (isBitiSet(byte, i))
      curr = curr->right;
    else
      curr = curr->left;

    if (isHuffTreeEmpty(curr->left) && isHuffTreeEmpty(curr->right))
    {
      stringToPrint[done ++] = curr->byte;
      curr = tree;
    }
  }

  for (j = 0; j < done; j ++)
    fprintf(newFile, "%c", stringToPrint[j]);

  printf("\n");
}
