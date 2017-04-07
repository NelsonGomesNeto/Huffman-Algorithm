#include "huffTree.h"
#include "list.h"

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
  unsigned char expression;
  if (scanf("%c", &expression) && expression == '*')
  {
    (*newTree) = createNode('*', 0);
    (*i) ++; createTreeFromPreFix(&(*newTree)->left, end, &*i);
    (*i) ++; createTreeFromPreFix(&(*newTree)->right, end, &*i);
  }
  else
  {
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
    printf("%c", tree->byte);
    printTreePreOrder(tree->left);
    printTreePreOrder(tree->right);
  }
}

void printTreeInOrder(huffTree_t *tree)
{
  if (!isHuffTreeEmpty(tree))
  {
    printTreeInOrder(tree->left);
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
    printf("%c", tree->byte);
  }
}
