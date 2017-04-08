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

void createTreeFromPreFix(huffTree_t **newTree, int end, int *i)
{
  if ((*i) == end) return;

  unsigned char expression;
  if (scanf("%c", &expression) && expression == '*')
  {
    (*newTree) = createNode('*', 0);
    (*i) ++; createTreeFromPreFix(&(*newTree)->left, end, &*i);
    (*i) ++; createTreeFromPreFix(&(*newTree)->right, end, &*i);
  }
  else
  {
    if (expression == 92)
    {
      int aux = expression;
      scanf("%c", &expression);
      if (expression == '*' || expression == 92)
        (*newTree) = createNode(expression, 0);
      else
      {
        (*newTree) = createNode(aux, 0);
      }
    }
    else
      (*newTree) = createNode(expression, 0);
  }
}

bool isHuffTreeEmpty(huffTree_t *hm)
{
  return(hm == NULL);
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

void createDictionary(huffTree_t *tree, unsigned char dictionary[][2], long long int frequency[], unsigned char byte, int depth)
{
	if(!isHuffTreeEmpty(tree))
	{
		if (isHuffTreeEmpty(tree->left) && isHuffTreeEmpty(tree->right))
		{
			dictionary[tree->byte][0] = byte >> (8 - depth);
			dictionary[tree->byte][1] = depth;
			frequency[tree->byte] = tree->frequency;
			//printf("[%c]", tree->byte);
		}
		else
		{
			//bits =  0;
			createDictionary(tree->left, dictionary, frequency, byte, depth + 1);
			byte = setBit(byte, (7 - depth)); //byte |= 1 << (7 - depth);
			createDictionary(tree->right, dictionary, frequency, byte, depth + 1);
		}
	}
}

int countTrashSize(unsigned char dictionary[][2], long long int frequency[])
{
	int i; long long int trashSize = 0;
	for(i = 0; i < 256; i++)
	{
		if(frequency[i] != -1)
			trashSize += (dictionary[i][1] * frequency[i]) % 8;
	}
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
