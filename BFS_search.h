//
// Created by LENOVO on 4/20/2024.
//

#ifndef BFS_BFS_SEARCH_H
#define BFS_BFS_SEARCH_H

#include "BFS_head.h"

bool do_BFS_Search(graph *g, int from, int to, bool *visited);
void shortest_path(graph *g , int from, int to);
bool * init_visited(graph *g, bool *visited_list);
#endif //BFS_BFS_SEARCH_H
