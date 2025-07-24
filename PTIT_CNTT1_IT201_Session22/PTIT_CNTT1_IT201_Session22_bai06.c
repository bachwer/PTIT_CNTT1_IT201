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
     Node *head;
};

typedef struct Graph {
    int maxSize;
    struct adjList *arr;
    int *visited;
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
            g -> arr[i].head = NULL;
        }
        g -> visited = calloc(size, sizeof(int));
    }
    return g;
}


void addEdge(Graph *g, const int src, const int dest) {
    Node *newNode = createNode(src);
    newNode -> next = g -> arr[dest].head;
    g -> arr[dest].head = newNode;

    newNode = createNode(dest);
    newNode -> next =g -> arr[src].head;
    g -> arr[src].head = newNode;
}


void DFS(Graph *g, const int start) {
    g -> visited[start] = 1;
    printf("%d ", start);
    Node *temp = g -> arr[start].head;
    while (temp != NULL) {
        if (!g -> visited[temp -> vertex]) {
            DFS(g, temp -> vertex);
        }
        temp = temp -> next;
    }
}
int main() {
    int v, e;
    printf("Nhap so dinh (v) va so canh (e): ");
    scanf("%d %d", &v, &e);


    Graph *g = initGraph(v);

    printf("Nhap danh sach %d canh (u v):\n", e);
    for (int i = 0; i < e; i++) {
        int u, v2;
        scanf("%d %d", &u, &v2);
        addEdge(g, u, v2);
    }

    int start;
    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &start);

    printf("Cac dinh duoc duyet theo DFS tu %d: ", start);
    DFS(g, start);
    printf("\n");

    return 0;
}



