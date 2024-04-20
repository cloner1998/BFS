//
// Created by LENOVO on 4/18/2024.
//

#include <stdbool.h>

#ifndef BFS_BFS_HEAD_H
#define BFS_BFS_HEAD_H

typedef struct graph_t {
    int num_nodes;
    bool **edges;
    bool **visited;
}graph;

graph *creat_graph(int value);
void destroy_graph(graph *g);
void print_graph(graph *g);
bool add_edge(graph *g, unsigned int from_node, unsigned int to_node);
bool has_edge(graph *g, unsigned int from_node, unsigned int to_node);

#endif //BFS_BFS_HEAD_H
