#include "BFS_search.h"
#include "BFS_head.h"
#include <stdlib.h>
#include <stdbool.h>

bool init_visited(graph *g, bool *visited_list){
    visited_list = calloc(g->num_nodes, sizeof (bool));
    return visited_list;
}
bool do_BFS_Search(graph *g, int from, int to, bool *visited){
    init_visited(g, visited);
    bool *connection = g->edges[from];
    bool found = false;
    for (int i = 0; i < g->num_nodes; ++i) {
        if(!connection[i] || visited[i]){
            continue;
        }
        visited[i] = true;
        if(connection[i] == g->edges[from][to]){
            found = true;
            break;
        }

    }
}
