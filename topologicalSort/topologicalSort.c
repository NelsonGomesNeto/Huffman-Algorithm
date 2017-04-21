#include "graph.h"

int main()
{
  int size; scanf("%d", &size);
  graph_t *graph = createGraph(size);

  int ini, fim;
  while (scanf("%d %d", &ini, &fim) != EOF)
    addEdge(graph, ini, fim);

  printGraph(graph);

  printf("\nDFS:\n"); dfs(graph, 1);

  printf("\nTopological Sort:\n"); topologicalSort(graph);

  destroyGraph(graph);
  return(0);
}
