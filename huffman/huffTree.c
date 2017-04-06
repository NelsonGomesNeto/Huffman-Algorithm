#include "huffTree.h"
#include "list.h"

struct _huffTree
{
  unsigned char byte;
  int frequency;
  huffTree_t *next;
  huffTree_t *left;
  huffTree_t *right;
};

huffTree_t* createNode(unsigned char byte, int frequency)
{
  huffTree_t *temp = (huffTree_t*) malloc(1 * sizeof(huffTree_t));
  temp->byte = byte;
  temp->frequency = frequency;
  temp->next = NULL;
  temp->left = NULL;
  temp->right = NULL;
  return(temp);
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

void addInHuffTree(huffTree_t *hm, unsigned char byte, int frequency)
{
  //huffTree_t *temp = createList(byte, frenquency);
  if (isHuffTreeEmpty(hm))
  {
    //hm = temp;
  }
  else
  {
    //temp->next = hm;

  }
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

void printNode(huffTree_t *atual)
{
  if (isHuffTreeEmpty(atual)) return;

  printf("Letra: %c || Frequencia: %d\n", atual->byte, atual->frequency);
}
