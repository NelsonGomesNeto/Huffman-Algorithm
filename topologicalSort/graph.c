#include "graph.h"
#include "stack.h"
#include "queue.h"

struct _graph
{
  int size;
  adjList_t **vertices;
  bool *visited;
};

struct _adjList
{
  int item;
  adjList_t *next;
};

graph_t* createGraph(int quantityNodes)
{
  graph_t *temp = (graph_t*) malloc(1 * sizeof(graph_t));
  temp->size = quantityNodes;
  temp->vertices = (adjList_t**) malloc(quantityNodes * sizeof(adjList_t*));
  temp->visited = (bool*) malloc(quantityNodes * sizeof(bool));
  int i;
  for (i = 0; i < quantityNodes; i ++)
  {
    temp->vertices[i] = NULL;
    temp->visited[i] = false;
  }
  return(temp);
}

adjList_t* newAdjList(int vertex)
{
  adjList_t *temp = (adjList_t*) malloc(1 * sizeof(adjList_t));
  temp->item = vertex;
  temp->next = NULL;
  return(temp);
}

void cleanVisits(graph_t *graph)
{
  int i;
  for (i = 0; i < graph->size; i ++)
    graph->visited[i] = false;
}

void addEdge(graph_t *graph, int startVertex, int endVertex)
{
  adjList_t *vertex = newAdjList(endVertex);
  vertex->next = graph->vertices[startVertex];
  graph->vertices[startVertex] = vertex;

  //Undirected graph has an Edge to the other direction as well.
  /*vertex = newAdjList(startVertex);
  vertex->next = graph->vertices[endVertex];
  graph->vertices[endVertex] = vertex;*/
}

void sub_dfs(graph_t *graph, int source)
{
  graph->visited[source] = true;
  printf("%d\n", source);

  adjList_t *curr = graph->vertices[source];

  while (curr != NULL)
  {
    if (!graph->visited[curr->item])
      sub_dfs(graph, curr->item);

    curr = curr->next;
  }
}

void dfs(graph_t *graph, int source)
{
  cleanVisits(graph);
  sub_dfs(graph, source);
}

void sub_topologicalSort(graph_t *graph, int i, stack_t *stack)
{
  graph->visited[i] = true;

  adjList_t *curr = graph->vertices[i];
  while (curr != NULL)
  {
    if (!graph->visited[curr->item])
      sub_topologicalSort(graph, curr->item, stack);

    curr = curr->next;
  }

  push(stack, i);
}

void topologicalSortDFS(graph_t *graph)
{
  stack_t *stack = newStack();

  cleanVisits(graph);

  int i;
  for (i = 0; i < graph->size; i ++)
    if (!graph->visited[i])
      sub_topologicalSort(graph, i, stack);

  while (!isStackEmpty(stack))
  {
    printf("%d\n", peek(stack));
    pop(stack);
  }

  destroyStack(stack);
}

void topologicalSortBFS(graph_t *graph)
{
  int inDegree[graph->size], i;
  for (i = 0; i < graph->size; i ++)
    inDegree[i] = 0;

  for (i = 0; i < graph->size; i ++)
  {
    adjList_t *curr = graph->vertices[i];
    while (curr != NULL)
    {
      inDegree[curr->item] ++;
      curr = curr->next;
    }
  }

  queue_t *queue = newQueue();
  for (i = 0; i < graph->size; i ++)
    if (inDegree[i] == 0)
      enqueue(queue, i);

  int counter = 0;
  queue_t *answer = newQueue();

  while (!isQueueEmpty(queue))
  {
    int current = front(queue);
    dequeue(queue);
    enqueue(answer, current);

    adjList_t *curr = graph->vertices[current];
    while (curr != NULL)
    {
      if (-- inDegree[curr->item] == 0)
        enqueue(queue, curr->item);

      curr = curr->next;
    }

    counter ++;
  }

  if (counter != graph->size)
  {
    printf("The graph isn't a DAG!\n");
    return;
  }

  while (!isQueueEmpty(answer))
  {
    printf("%d\n", front(answer));
    dequeue(answer);
  }
  destroyQueue(queue);
  destroyQueue(answer);
}

void printGraph(graph_t *graph)
{
  if (graph == NULL) return;
  printf("Graph (%d nodes):\n", graph->size);
  int i;
  for (i = 0; i < graph->size; i ++)
  {
    printf("%d ~>", i);
    adjList_t *curr = graph->vertices[i];
    while (curr != NULL)
    {
      printf(" %d", curr->item);
      curr = curr->next;
    } printf("\n");
  }
}

void destroyGraph(graph_t *graph)
{
  int i;
  for (i = 0; i < graph->size; i ++)
  {
    adjList_t *curr = graph->vertices[i];
    while (curr != NULL)
    {
      graph->vertices[i] = graph->vertices[i]->next;
      free(curr);
      curr = graph->vertices[i];
    }
    free(curr);
    free(graph->vertices[i]);
  }
  free(graph->vertices);
  free(graph->visited);
  free(graph);
}
