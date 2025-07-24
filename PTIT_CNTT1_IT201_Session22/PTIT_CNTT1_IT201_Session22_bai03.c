//
// Created by Macbook on 24/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#define max 5


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
    Graph *newG = malloc(sizeof(Graph));
    newG -> maxSize = size;
    newG -> arr = malloc(size *sizeof(struct adjList));

    for (int i = 0; i < size ; i++) {
        newG -> arr[i].head = NULL;
    }
    return newG;
}


void addEdge(Graph *g, const int src , const int dest) {
    Node *newNode = createNode(dest);
    newNode -> next = g -> arr[src].head;
    g -> arr[src].head = newNode;


    newNode = createNode(src);
    newNode -> next = g -> arr[dest].head;
    g -> arr[dest].head = newNode;
}

void showGraph(Graph *g) {
    for ( int i = 0; i < g -> maxSize; i++) {
        Node *temp = g -> arr[i].head;
        printf("%d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp -> vertex);
            temp = temp -> next;
        }
        printf("\n");
    }
}

void addEqualM(int **arr, Graph *g) {
    for (int i = 0; i < max; i++) {
        for (int j = i + 1; j < max ; j++) {
           if (arr[i][j] == 1) {
               addEdge(g, i, j);
           }
        }
    }
}

int main() {
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

    addEqualM(arr,g);

    showGraph(g);

}