//
// Created by Macbook on 24/07/2025.
//
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int vertex;
    struct Node *next;
}Node;

struct adjList {
    struct Node *head;
};

typedef struct Graph {
    int maxSize;
    struct adjList *arr;
}Graph;

Node *createNode(const int val) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode -> vertex = val;
        newNode -> next = NULL;
    }
    return newNode;
}
Graph *newGraph(const int size) {
    Graph *newGraph = malloc(sizeof(Graph));
    newGraph -> maxSize = size;
    newGraph -> arr = malloc(size * sizeof(struct adjList));
    for (int i = 0; i < size; i++) {
        newGraph -> arr[i].head = NULL;
    }
    return newGraph;
}

void addToGraph(Graph *g, const int src, const int dest) {
    Node *newNode = createNode(src);
    newNode -> next = g -> arr[dest].head;
    g -> arr[dest].head = newNode;


    newNode = createNode(dest);
    newNode -> next = g -> arr[src].head;
    g -> arr[src].head = newNode;
}
void check(int **arr, const int max) {
    int count = 0;
    for (int i = 0; i < max; i++) {
        for (int j = i+ 1; j < max; j++) {
            if (arr[i][j] == 1) {
                count++;
            }
        }
    }
    printf("\n%d", count);
}


int main() {
    int max; scanf("%d", &max);
    Graph *g = newGraph(max);

    int **arr = malloc(max * sizeof(int *));
    for (int i = 0; i < max; i++) {
        arr[i] = malloc(max * sizeof(int));
    }
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max ; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    check(arr,max);
}



