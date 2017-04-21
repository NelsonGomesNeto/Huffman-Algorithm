#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
typedef struct stack_t stack_t;
typedef struct node_t node_t;

node_t* newNode(int value); //Novo nó
stack_t* newStack(); //Nova pilha
bool isEmpty(stack_t *stack); //Está vazia?
bool isFull(stack_t *stack); //Está cheia?
int peek(stack_t *stack); //Olhar o do topo
int cap(stack_t *stack); //Capacidade
int size(stack_t *stack); //Tamanho atual
void push(stack_t *stack, int value); //Adiciona
void pop(stack_t *stack); //Remove
bool destroy(stack_t *stack); //Destrói

#endif //STACK_H
