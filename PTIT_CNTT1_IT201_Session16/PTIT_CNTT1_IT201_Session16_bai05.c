//
// Created by Macbook on 11/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct {
    Node *front;
    Node *rear;
}Queue;

Node *createNode(const int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Failed to allocate memory: ");
        return NULL;
    }
    newNode -> data = val;
    newNode -> next = NULL;
    return newNode;
}

Queue *createQue() {
    Queue *newQue = (Queue *)malloc(sizeof(Queue));
    if (newQue == NULL) {
        printf("Failed to allocate memory: ");
        return NULL;
    }
    newQue -> front = newQue -> rear = NULL;
    return newQue;
}

int isEmpty(const Queue *q) {
    return q -> front == NULL;
}

void endQue(Queue *q, const int val) {
    Node* newNode = createNode(val);
    if (q -> front == NULL) {
        q -> front = q -> rear = newNode;
        return;
    }
    q -> rear -> next =  newNode;
    q -> rear =  newNode;
}

int delQue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    const int tempData = q -> front -> data;
    Node *temp = q -> front;
    q -> front = q -> front -> next;
    free(temp);
    if (q -> front == NULL) {
        q -> rear = NULL;
    }
    return tempData;
}

void printQue(const Queue *q) {
    const Node *current = q -> front;
    while (current != NULL) {
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("NULL\n");

}

void freeQue(Queue *q) {
    while (!isEmpty(q)) {
        delQue(q);
    }
    free(q);
}
int main() {
    Queue *q = createQue();
    if (q == NULL) {
        return -1;
    }
    for (int i = 0; i < 5; i++) {
        endQue(q, i + 1);
    }
    printQue(q);

    delQue(q);

    printQue(q);

    freeQue(q);
    return 0;
}





