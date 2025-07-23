//
// Created by Macbook on 23/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 5

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *createNode(const int val) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode -> data = val;
        newNode -> next =  NULL;
    }
    return newNode;
}

void addEdge(Node *g[], int src, int dest) {
    Node *newNode = createNode(dest);
    newNode -> next = g[src];
    newNode = createNode(src);
    newNode -> next = g[dest];
    g[dest] = newNode;
}

void printG(Node * g[], int ver) {
    for (int i = 0; i < ver; i++) {
        Node *temp =g[i];
        while (temp != NULL) {
            printf("%d -> ", temp -> data);
            temp = temp -> next;
        }
        printf("NULL\n");
    }

}

int main() {
    Node* graph[MAX_VERTICES] = {NULL};

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printG(graph, MAX_VERTICES);

    return 0;
}


