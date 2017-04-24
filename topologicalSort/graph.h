#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

/*
 * typedef of a graph struct: graph_t
 * ----------------------------
 */
typedef struct _graph graph_t;

/*
 * typedef of an adjacent list struct: adjList_t
 * ----------------------------
 */
typedef struct _adjList adjList_t;

/*
 * Function: createGraph
 * ----------------------------
 *   quantityNodes: integer with how many nodes the graph will have
 *
 *   returns: graph_t* of the created graph.
 */
graph_t* createGraph(int quantityNodes);

/*
 * Function: newAdjList
 * ----------------------------
 *   Create a vertex
 *
 *   vertex: integer to have a vertex created
 *
 *   returns: adjList_t* of the created vertex
 */
adjList_t* newAdjList(int vertex);

/*
 * Function: addEdge
 * ----------------------------
 *   Adds a Edge to the graph
 *
 *   graph: graph_t *graph to have a edge added
 *   startVertex: integer which starts the edge
 *   endVertex: integer which ends the edge
 *
 *   returns: nothing
 */
void addEdge(graph_t *graph, int startVertex, int endVertex);

/*
 * Function: dfs
 * ----------------------------
 *   Do a depth-first search
 *
 *   graph: graph_t *graph to do dfs
 *   source: integer that is the vertex on which start the dfs
 *
 *   returns: nothing
 */
void dfs(graph_t *graph, int source);

/*
 * Function: topologicalSortDFS
 * ----------------------------
 *   Do a Topological Sort on graph with dfs
 *
 *   graph: graph_t *graph to do a  Topological Sort
 *
 *   returns: nothing
 */
void topologicalSortDFS(graph_t *graph);

/*
 * Function: topologicalSortBFS
 * ----------------------------
 *   Do a Topological Sort on graph with bfs
 *
 *   graph: graph_t *graph to do a  Topological Sort
 *
 *   returns: nothing
 */
void topologicalSortBFS(graph_t *graph); // aka Kahn's algorithm

/*
 * Function: printGraph
 * ----------------------------
 *   Print a graph
 *
 *   graph: graph_t *graph to be printed
 *
 *   returns: nothing
 */
void printGraph(graph_t *graph);

/*
 * Function: destroyGraph
 * ----------------------------
 *   Free memory
 *
 *   graph: graph_t *graph to be destroyed
 *
 *   returns: nothing
 */
void destroyGraph(graph_t *graph);

#endif //GRAPH_H
