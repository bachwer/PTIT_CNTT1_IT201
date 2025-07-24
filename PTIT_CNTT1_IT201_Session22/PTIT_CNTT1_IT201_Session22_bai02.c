//
// Created by Macbook on 24/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#define max 5


typedef struct Graph {
    int maxSize;
    int arr[max][max];
}Graph;

void initGraph(Graph *g, const int size) {
    g -> maxSize = size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j< size; j++) {
            g -> arr[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, const int u, const int v) {
    if (u >= 0 && u < g -> maxSize && v >= 0 && v < g -> maxSize) {
        g -> arr[u][v] = 1;
        g -> arr[v][u] = 1;
    }
}

void showGraph(const Graph *g) {
    for (int i = 0; i < g -> maxSize; i++) {
        printf("%d: ", i);
        for (int j = 0 ; j < g -> maxSize; j++) {
            if (g -> arr[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    int n; scanf("%d", &n);
    Graph g;
    initGraph(&g, max);
    for ( int i = 0; i < n; i++) {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);
        addEdge(&g, a,b);
    }
    showGraph(&g);


}