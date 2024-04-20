#include "BFS_search.h"
#include "BFS_head.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool * init_visited(graph *g, bool *visited_list){
    visited_list = calloc(g->num_nodes, sizeof (bool));
    return visited_list;
}
bool do_BFS_Search(graph *g, int from, int to, bool *visited){
    init_visited(g, visited);
    bool *connection = g->edges[from];
    bool found = false;
    printf("pushed %d\n", from);
    for (int i = 0; i < g->num_nodes; ++i) {
        if(!connection[i] || visited[i]){
            continue;
        }
        visited[i] = true;
        if(i == to){
            found = true;
            printf("found %d\n", i);
            break;
        }
        found = do_BFS_Search(g, i, to, visited);
        if(found){
            break;
        }

    }
    if(!found){
        printf("popped %d\n", from);
    }
    return found;
}

void shortest_path(graph *g , int from, int to){
    bool *visited = calloc(g->num_nodes, sizeof (bool));
    do_BFS_Search(g, from, to, visited);
    free(visited);
}