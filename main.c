#include <stdio.h>
#include "BFS_head.h"
#include "BFS_search.h"

int main() {
    graph *g = creat_graph(6);
    add_edge(g, 0, 1);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 5);
    add_edge(g, 2, 4);
    add_edge(g, 0, 4);
    shortest_path(g, 0, 3);
    return 0;
}
