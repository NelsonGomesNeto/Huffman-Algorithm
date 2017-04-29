#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
typedef struct _Stack Stack_t;
typedef struct _NodeStack NodeStack_t;

NodeStack_t* newNodeStack(int value); //Novo nó
Stack_t* newStack(); //Nova pilha

bool isStackEmpty(Stack_t *stack); //Está vazia?
bool isFull(Stack_t *stack); //Está cheia?
int peek(Stack_t *stack); //Olhar o do topo
int cap(Stack_t *stack); //Capacidade
int size(Stack_t *stack); //Tamanho atual

void push(Stack_t *stack, int value); //Adiciona

void pop(Stack_t *stack); //Remove
bool destroyStack(Stack_t *stack); //Destrói

#endif //STACK_H
