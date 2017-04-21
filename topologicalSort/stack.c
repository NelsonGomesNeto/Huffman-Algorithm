#include "stack.h"

/*
int main()
{
  stack_t *stack = newStack();
  printf("Cap: %d; Size: %d; Peek: %d\n", cap(stack), size(stack), peek(stack));
  int i;
  for (i = 1; i <= 10; i ++)
    push(stack, i * 2);

  for (i = 0; i < 10; i ++)
  {
    printf("%d, %d\n", peek(stack), size(stack));
    pop(stack);
  }

  destroy(stack);
  return(0);
}
*/

struct node_t
{
  int value;
  node_t *bot;
};

struct stack_t
{
  int size;
  int cap;
  node_t *top;
};

node_t* newNode(int value)
{
  node_t *temp = (node_t*) malloc(1 * sizeof(node_t));
  temp->value = value;
  temp->bot = NULL;
  return(temp);
}

stack_t* newStack()
{
  stack_t *temp = (stack_t*) malloc(1 * sizeof(node_t));
  temp->size = 0;
  temp->cap = INT_MAX;
  return(temp);
}

bool isEmpty(stack_t *stack)
{
  return(!stack->size);
}

bool isFull(stack_t *stack)
{
  return(stack->size == stack->cap);
}

int peek(stack_t *stack)
{
  if (isEmpty(stack)) return INT_MIN;
  return(stack->top->value);
}

int cap(stack_t *stack)
{
  return(stack->cap);
}
int size(stack_t *stack)
{
  return(stack->size);
}

void push(stack_t *stack, int value)
{
  if (isFull(stack)) return;
  node_t *temp = newNode(value);
  if (isEmpty(stack))
  {
    stack->top = temp;
  }
  else
  {
    temp->bot = stack->top;
    stack->top = temp;
  }
  stack->size ++;
}

void pop(stack_t *stack)
{
  if (isEmpty(stack)) return;
  node_t *temp = stack->top->bot;
  free(stack->top);
  stack->top = temp;
  stack->size --;
}

bool destroy(stack_t *stack)
{
  while (!isEmpty(stack))
    pop(stack);

  free(stack);
  return(true);
}
