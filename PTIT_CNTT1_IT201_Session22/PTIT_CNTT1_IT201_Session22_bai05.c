//
// Created by Macbook on 24/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node * next;
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

Graph *initGraph(const int size) {
    Graph *g = malloc(sizeof(Graph));
    if (g != NULL) {
        g -> maxSize = size;
        g -> arr = malloc(size * sizeof(struct adjList));
        for (int i = 0; i < size; i++) {
            g -> arr[i].head == NULL;
        }
    }
    return g;
}


void addEdge(Graph *g, const int src, const int dest) {
    Node *newNode = createNode(dest);
    newNode -> next = g -> arr[src].head;
    g -> arr[src].head = newNode;

    newNode = createNode(src);
    newNode -> next = g -> arr[dest].head;
    g -> arr[dest].head = newNode;
}

void check(const Graph *g, const int vex) {
    int count = 0;
    for (int i = 0; i < g -> maxSize; i++) {
        const Node *temp = g -> arr[i].head;
        while (temp != NULL) {
           if (temp -> vertex == vex) {
               count++;
           }
            temp = temp -> next;
        }
    }
    printf("So dinh ke voi %d la: %d",vex, count);

}

int main() {

    int row; scanf("%d", &row);
    int cols; scanf("%d", &cols);
    Graph *g = initGraph(row);

    for (int i = 0; i < cols; i++) {
        const int a, b;
        scanf("%d", &a);scanf("%d", &b);
        addEdge(g, a, b);
    }

    int n;
    printf("Nhap so dinh: ");scanf("%d", &n);

    check(g,n);








}



