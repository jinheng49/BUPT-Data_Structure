#include <stdio.h>


#define MAX_VERTICES 8


void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertex, int visited[MAX_VERTICES]) {
    printf("%d,", vertex);
    visited[vertex - 1] = 1;  
    for (int i =1; i <= MAX_VERTICES; i++) {
        if (graph[vertex - 1][i - 1] == 1 && !visited[i - 1]) { 
            DFS(graph, i, visited);
        }
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 1, 1, 1, 0}
    };

    int visited[MAX_VERTICES] = {0};

    int startVertex;
    scanf("%d", &startVertex);

    DFS(graph, startVertex, visited);

    printf("\n");

    return 0;
}
