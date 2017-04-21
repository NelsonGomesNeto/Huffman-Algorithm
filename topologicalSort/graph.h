#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct _graph graph_t;
typedef struct _adjList adjList_t;

graph_t* createGraph(int quantityNodes);
adjList_t* newAdjList(int vertex);

void addEdge(graph_t *graph, int startVertex, int endVertex);

void dfs(graph_t *graph, int source);
void topologicalSort(graph_t *graph);
//void bfs(graph_t* graph, int source);

void printGraph(graph_t *graph);

void destroyGraph(graph_t *graph);

#endif //GRAPH_H
