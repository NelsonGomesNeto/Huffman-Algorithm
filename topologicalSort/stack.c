#include "stack.h"

struct nodeStack_t
{
  int value;
  nodeStack_t *bot;
};

struct stack_t
{
  int size;
  int cap;
  nodeStack_t *top;
};

nodeStack_t* newNodeStack(int value)
{
  nodeStack_t *temp = (nodeStack_t*) malloc(1 * sizeof(nodeStack_t));
  temp->value = value;
  temp->bot = NULL;
  return(temp);
}

stack_t* newStack()
{
  stack_t *temp = (stack_t*) malloc(1 * sizeof(nodeStack_t));
  temp->size = 0;
  temp->cap = INT_MAX;
  return(temp);
}

bool isStackEmpty(stack_t *stack)
{
  return(!stack->size);
}

bool isFull(stack_t *stack)
{
  return(stack->size == stack->cap);
}

int peek(stack_t *stack)
{
  if (isStackEmpty(stack)) return INT_MIN;
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
  nodeStack_t *temp = newNodeStack(value);
  if (isStackEmpty(stack))
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
  if (isStackEmpty(stack)) return;
  nodeStack_t *temp = stack->top->bot;
  free(stack->top);
  stack->top = temp;
  stack->size --;
}

bool destroyStack(stack_t *stack)
{
  while (!isStackEmpty(stack))
    pop(stack);

  free(stack);
  return(true);
}
