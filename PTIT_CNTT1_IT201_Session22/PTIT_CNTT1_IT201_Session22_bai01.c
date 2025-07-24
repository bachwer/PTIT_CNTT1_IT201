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

void initGraph(Graph *g,const int size) {
    g -> maxSize = size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            g -> arr[i][j] = 0;
        }
    }
}


void addEdge(Graph *g, const int u, const int v) {
    if (u >= 0 && u < g -> maxSize && v >= 0 && v < g -> maxSize) {
        g ->arr[u][v] = 1;
        g ->arr[v][u] = 1;
    }
}

void printfGraph(Graph *g) {
    for (int i = 0; i < g -> maxSize; i++) {
        for (int j = 0 ; j < g -> maxSize; j++) {
            printf("%d ", g -> arr[i][j]);
        }
        printf("\n");
    }
}

void printGraph2(Graph *g) {
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
    for (int i = 0; i < n; i++) {
        int v = 0;
        int u = 0;
        scanf("%d", &v);
        scanf("%d", &u);
        addEdge(&g,u, v );
    }
    printf("\n");

    printfGraph(&g);
    printf("----------\n");
    printGraph2(&g);

}