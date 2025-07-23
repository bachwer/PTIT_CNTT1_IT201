//
// Created by Macbook on 23/07/2025.
//

#include <stdio.h>

#define max 3

struct Graph {
    int maxSize;
    int arr[max][max];
};

void initGraph(struct Graph *g,const int size) {
    g -> maxSize = size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            g -> arr[i][j] = 0;
        }
    }
}


void addEdge(struct Graph *g, const int u, const int v) {
    if (u >= 0 && u < g -> maxSize &&  v >= 0 && v < g -> maxSize ) {
        g -> arr[u][v] = 1;
    }
}

void showGrap(struct Graph *g) {

    for (int i = 0; i < g -> maxSize; i++) {
        for (int j = 0; j < g -> maxSize; j++) {
            printf("%d ", g ->arr[i][j]);
        }
        printf("\n");
    }
}










int main() {

    struct Graph g;
    initGraph(&g, max);
    showGrap(&g);
    printf("--------\n");

    addEdge(&g,  1, 0);
    addEdge(&g,  1, 2);
    addEdge(&g,  2, 0);
    showGrap(&g);



}

