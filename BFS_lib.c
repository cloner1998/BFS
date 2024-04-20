#include "BFS_head.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct graph_t {
    int num_nodes;
    bool **edges;
    bool **visited;
}graph;

graph *creat_graph(int num_nodes){
    graph *g = malloc(sizeof (graph));
    g->num_nodes = num_nodes;
    g->edges = (bool **)malloc(sizeof (bool *) * num_nodes);
    g->visited = (bool **)malloc(sizeof (bool *) * num_nodes);
    for (int i = 0; i < num_nodes; ++i) {
        g->edges[i] = malloc(sizeof (bool) * num_nodes);
        g->visited[i] = malloc(sizeof (bool) * num_nodes);
        for (int j = 0; j < num_nodes; ++j) {
            g->edges[i][j] = false;
            g->visited[i][j] = false;
        }
    }
    return g;
}

void destroy_graph(graph *g){
    if(g->edges == NULL){
        free(g);
        return;
    }
    for (int i = 0; i < g->num_nodes; ++i) {
        if(g->edges[i] != NULL){
            free(g->edges[i]);
        }
    }
    free(g->edges);
    free(g);
}
void print_graph(graph *g){
    printf("digraph {\n");
    for (int i = 0; i < g->num_nodes; ++i) {
        for (int j = 0; j < g->num_nodes; ++j) {
            if(g->edges[i][j]){
                printf("%d -> %d;\n",i , j);
            }
        }

    }
    printf("}\n");
}
bool add_edge(graph *g, unsigned int from_node, unsigned int to_node){
    if(has_edge(g, from_node, to_node)){
        return false;
    }
    g->edges[from_node][to_node] = true;
    return true;
}
bool has_edge(graph *g, unsigned int from_node, unsigned int to_node){
    return g->edges[from_node][to_node];
}

