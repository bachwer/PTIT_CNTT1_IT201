//
// Created by Macbook on 11/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node *front;
    Node *rear;
}Queue;

Node *createNode(const int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Failed to allocate memory!!\n ");
        return NULL;
    }
    newNode -> data = val;
    newNode -> next = NULL;
    return newNode;
}

Queue *createQue() {
    Queue *newQue = (Queue *)malloc(sizeof(Queue));
    if (newQue == NULL) {
        printf("Failed to allocate memory \n");
        return NULL;
    }
    newQue -> front =newQue -> rear = NULL;
    return newQue;
}
int isEmpty(const Queue *q) {
    return q -> front == NULL;
}

void endQue(Queue *q, const int val) {
    Node *temp = createNode(val);
    if (temp == NULL) {
        return;
    }

    if (q -> front == NULL) {
        q -> front = q -> rear = temp;
    }

    q -> rear -> next = temp;
    q -> rear =  temp;
}

int delQue(Queue *q) {
    if (isEmpty(q)) {
        return -1;
    }

    const int temp = q -> front -> data;
    Node *tempNode = q -> front;
    q -> front = q -> front -> next;
    free(tempNode);
    if ( q -> front == NULL) {
        q -> rear = NULL;
    }
    return temp;
}

void printQue(const Queue *q) {
    const Node *current = q -> front;
    while (current != NULL) {
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("NULL");
}
void freeQue(Queue *q) {
    while (!isEmpty(q)) {
        delQue(q);
    }
    free(q);
}

void main() {
    Queue *q = createQue();
    if (q == NULL) {
        return;
    }
    for (int i = 0; i < 5; i++) {
        endQue(q, i + 1);
    }

    printQue(q);
    freeQue(q);
}