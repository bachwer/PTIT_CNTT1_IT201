//
// Created by Macbook on 21/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;

}Node;

Node *createNode(const int data) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode -> data = data;
        newNode -> left = newNode -> right = NULL;
    }
    return newNode;
}
typedef struct QueueNode {
    Node *data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
}Queue;

Queue *createQue() {
    Queue *q = malloc(sizeof(Queue));
    if (q != NULL) {
        q -> front = q -> rear = NULL;
    }
    return q;
}

bool isEmpty(const Queue *q) {
    return q -> front == NULL;
}

void endQue(Queue *q, const Node *treeNode) {
    if (treeNode == NULL) return;

    QueueNode *newNode = malloc(sizeof(QueueNode));
    if (newNode == NULL) return;

    newNode->data = treeNode;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}



Node *delQue(Queue *q) {
    if (isEmpty(q)) return NULL;
    QueueNode *temp = q -> front;
    Node *data = temp -> data;
    q -> front = q -> front -> next;
    if (q -> front == NULL) q -> rear = NULL;
    free(temp);
    return data;
}

void freeQueue(Queue *q) {
    while (!isEmpty(q)) {
        delQue(q);
    }
    free(q);
}

bool BFS(Node *root, int val) {
    if (root == NULL) return false;

    Queue *q =  createQue();
    endQue(q, root);

    while (!isEmpty(q)) {
        Node *current = delQue(q);
        if (current -> data == val) {
            freeQueue(q);
            return true;
        }
        if ( current -> left) endQue(q, current -> left);
        if ( current -> right) endQue(q, current -> right);

    }
    freeQueue(q);
    return false;

}






int main() {
    Node *root = createNode(2);
    root -> left = createNode(3);
    root -> left -> left = createNode(5);
    root -> right = createNode(4);

    const int target = 4;

    if (BFS(root, target)) {
        printf("True");
    }else {
        printf("False");
    }



}
