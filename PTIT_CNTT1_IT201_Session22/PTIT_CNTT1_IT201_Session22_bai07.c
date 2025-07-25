#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;
typedef struct Queue {
     Node *front;
     Node *rear;
}Queue;

struct adjList {
     Node *head;
};


typedef struct Graph {
    int maxSize;
    struct adjList *arr;
    int *visited;
}Graph;

Graph *initGraph(const int size) {
    Graph *g = malloc(sizeof(Graph));
    if (g != NULL) {
        g -> maxSize = size;
        g -> arr = malloc(size * sizeof(struct adjList));
        for (int i = 0 ; i < size; i++) {
            g -> arr[i].head = NULL;
        }
    }
    return g;
}


Node *newNode(const int val) {
    Node *new = malloc(sizeof(Node));
    if (new != NULL) {
        new -> data = val;
        new -> next = NULL;
    }
    return new;
}
bool isEmpty(Queue *q) {
    return q -> front == NULL;
}
Queue *newQue() {
    Queue *q = malloc(sizeof(Queue));
    if (q != NULL) {
        q -> front = q -> rear = NULL;
    }
    return q;
}

void endQue(Queue *q, const int value) {
    Node *node = newNode(value);
    if ( q -> rear == NULL) {
        q -> front = q -> rear = node;
    }else {
        q -> rear -> next = node;
        q -> rear = node;
    }
}

int delQue(Queue *q) {
    if (isEmpty(q)) return - 1;

    Node *temp = q -> front;
    const int data = q -> front -> data;
    q -> front = q -> front -> next;

    if (q -> front == NULL) {
        q -> rear = NULL;
    }

    free(temp);

    return data;
}


void addEdge(Graph *g, const int src, const int dest) {
    Node *node = newNode(dest);
    node -> next = g -> arr[src].head;
    g -> arr[src].head = node;

    node = newNode(src);
    node -> next = g-> arr[dest].head;
    g -> arr[dest].head = node;
}
void BFS(Graph *g, const int start, const int numVertices) {
    g -> visited = malloc(numVertices*sizeof(int));
    g -> visited[start] = 1;
    Queue *q = newQue();
    endQue(q, start);
    while (!isEmpty(q)) {
        int current = delQue(q);
        printf("%d ", current);
        Node *temp = g -> arr[current].head;
        while (temp != NULL) {
            const int near = temp -> data;
            if (!g -> visited[near]) {
                g -> visited[near] = 1;
                endQue(q, near);
            }
            temp = temp -> next;
        }
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
    BFS(g, start, v);
    printf("\n");

    return 0;









}