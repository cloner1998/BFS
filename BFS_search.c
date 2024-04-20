#include "BFS_search.h"
#include "BFS_head.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int my_list[6];
int top = 0;

bool push(int value) {
    if(top >= 6) return  false;
    my_list[top] = value;
    top ++;
    return true;
}

int pop(){
    if(top == 0) return -1;
    int result = my_list[top];
    top --;
    return result;
}

bool * init_visited(graph *g, bool *visited_list){
    visited_list = calloc(g->num_nodes, sizeof (bool));
    return visited_list;
}

bool do_BFS_Search(graph *g, int from, int to, bool *visited){
    init_visited(g, visited);
    bool *connection = g->edges[from];
    bool found = false;
    //printf("pushed %d\n", from);
    push(from);
    printf("(push)stack level %d, my top = %d \n", from, top);
    for (int i = 0; i < g->num_nodes; ++i) {
        if(!connection[i] || visited[i]){
            continue;
        }
        visited[i] = true;
        if(i == to){
            found = true;
            //printf("found %d\n", i);
            push(i);
            printf("(push)stack level %d my top = %d\n", i, top);
            break;
        }
        found = do_BFS_Search(g, i, to, visited);
        if(found){
            push(i);
            printf("(push)stack level %d(mine?), my top = %d\n", i, top);
            break;
        }

    }
    if(!found){
        //printf("popped %d\n", from);
        pop();
        printf("(pop)stack level %d, my top = %d\n", from, top);
    }
    return found;
}

void shortest_path(graph *g , int from, int to){
    bool *visited = calloc(g->num_nodes, sizeof (bool));
    do_BFS_Search(g, from, to, visited);
    free(visited);
}

void print_list(){
    for (int i = 0; i < top; ++i) {
        printf("%d-", my_list[i]);
    }
    printf("\n");
}