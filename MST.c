#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10

typedef struct {
    int vertices;       
    int edges[MAX_VERTICES][MAX_VERTICES];  
} Graph;


void initGraph(Graph *graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            graph->edges[i][j] = INT_MAX;  
        }
    }
}

void addEdge(Graph *graph, int from, int to, int weight) {
    graph->edges[from][to] = weight;
    graph->edges[to][from] = weight;  
}
void changeEdge(Graph *graph, int from, int to,int weight){
    graph->edges[from][to] = weight;
    graph->edges[to][from] = weight;
}



void primMST(Graph *graph, int mstEdges[], int *mstEdgeCount) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    int mstSet[MAX_VERTICES];

    for (int i = 0; i < graph->vertices; ++i) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;    
    parent[0] = -1; 

    *mstEdgeCount = 0; 

    for (int count = 0; count <= graph->vertices - 1; ++count) {
        int u, minKey = INT_MAX;
        for (int v = 0; v < graph->vertices; ++v) {
            if (mstSet[v] == 0 && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        mstSet[u] = 1;

        for (int v = 0; v < graph->vertices; ++v) {
            if (graph->edges[u][v] && mstSet[v] == 0 && graph->edges[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->edges[u][v];
            }
        }


        if (parent[u] != -1) {
            mstEdges[(*mstEdgeCount)++] = graph->edges[u][parent[u]];
        }
    }
}


int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int main() {
    Graph myGraph;
    initGraph(&myGraph, 10);

    addEdge(&myGraph, 0, 1, 3);
    addEdge(&myGraph, 0, 3, 4);
    addEdge(&myGraph, 0, 4, 4);
    addEdge(&myGraph, 1, 2, 10);
    addEdge(&myGraph, 1, 5, 3);
    addEdge(&myGraph, 1, 4, 2);
    addEdge(&myGraph, 2, 6, 1);
    addEdge(&myGraph, 2, 5, 6);
    addEdge(&myGraph, 3, 4, 5);
    addEdge(&myGraph, 3, 7, 6);   
    addEdge(&myGraph, 4, 7, 2);
    addEdge(&myGraph, 4, 5, 11);
    addEdge(&myGraph, 4, 8, 1);
    addEdge(&myGraph, 5, 6, 2);
    addEdge(&myGraph, 5, 8, 3);
    addEdge(&myGraph, 5, 9, 11);
    addEdge(&myGraph, 6, 9, 8);
    addEdge(&myGraph, 7, 8, 4);
    addEdge(&myGraph, 8, 9, 7);

    char fromc,toc;
    int from,to;
    int weight;
    scanf("%c,%c,%d",&fromc,&toc,&weight);
    from = fromc - 'A';
    to = toc - 'A';
    changeEdge(&myGraph,from,to,weight);

    int mstEdges[MAX_VERTICES];
    int mstEdgeCount = 0;


    primMST(&myGraph, mstEdges, &mstEdgeCount);


    qsort(mstEdges, mstEdgeCount, sizeof(int), compare);

    for (int i = 0; i <  mstEdgeCount; ++i) {
        printf("%d,", mstEdges[i]);
    }

    return 0;
}
