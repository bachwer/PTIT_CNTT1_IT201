//
// Created by Macbook on 23/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 3


struct Graph {
    int numVertices;
    int arr[MAX_VERTICES][MAX_VERTICES];
};

void initGraph(struct Graph* graph, const int numVer){
    graph -> numVertices = numVer;
    for (int i = 0; i < numVer; i ++) {
        for (int j = 0; j < numVer; j++) {
            graph -> arr[i][j] = 0;
        }
    }
}

void addEdge(struct Graph *graph, const int u, const int v) {
    if (u >= 0 && u < graph->numVertices && v >= 0 && v < graph->numVertices) {
        graph->arr[u][v] = 1;
        graph->arr[v][u] = 1;
    }
}


void printfGraph(struct Graph *g) {
    for (int i = 0; i < g -> numVertices; i++) {
        for (int j = 0; j < g -> numVertices; j++) {
            printf("%d ", g -> arr[i][j]);
        }
        printf("\n");
    }
}


int main() {
    struct Graph graph;

    initGraph(&graph, MAX_VERTICES);
    printfGraph(&graph);
    printf("-------------\n");
    const int node1 = 1;
    const int node2 = 2;
    addEdge(&graph, node1, node2);
    printfGraph(&graph);

}
