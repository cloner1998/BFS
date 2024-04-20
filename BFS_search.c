#include "BFS_search.h"
#include "BFS_head.h"
#include <stdlib.h>
#include <stdbool.h>


bool do_BFS_Search(graph *g, int from, int to, bool *visited){
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
