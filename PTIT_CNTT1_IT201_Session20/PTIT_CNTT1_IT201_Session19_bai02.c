//
// Created by Macbook on 22/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
typedef struct QueueNode {
    Node *data;
    struct QueueNode *next;
}QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;

}Queue;

Queue *newQue() {
    Queue *newQue = malloc(sizeof(Queue));
    if (newQue) {
        newQue -> front = newQue -> rear = NULL;
    }
    return newQue;
}
 void endQue(Queue *q, const Node *node) {
    if (node == NULL) return;

    QueueNode *newNode = malloc(sizeof(QueueNode));
    if (newNode == NULL) return;
    newNode -> data = node;
    newNode -> next = NULL;
    if ( q-> rear == NULL) {
        q -> front = q -> rear = newNode;
    }else {
        q -> rear -> next = newNode;
        q -> rear = newNode;
    }
}

int isEmpty(const Queue *q) {
    return q -> front == NULL;
}

Node *delQue(Queue *q) {
    if (isEmpty(q)) {
        return NULL;
    }
    QueueNode *temp = q -> front;
    Node *data = q -> front -> data;
    q -> front = q -> front -> next;
    if (q -> front == NULL) q -> rear = NULL;
    free(temp);
    return data;
}


Node *createNode(const int data) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode -> data = data;
        newNode -> left = newNode -> right = NULL;
    }
    return newNode;
}

void preOrder(const Node *root) {
    if (root == NULL) return;
    printf("%d ", root -> data);
    preOrder(root -> left);
    preOrder(root -> right);

}
void inOrder(const Node *root) {
    if (root == NULL) return;

    inOrder(root -> left);
    printf("%d ", root -> data);
    inOrder(root -> right);
}


void posOrder(const Node *root) {
    if (root == NULL) return;

    posOrder(root -> left);
    posOrder(root -> right);
    printf("%d ", root -> data);

}

void levelOrder(const Node *root) {
    if (root == NULL) return;
    Queue *q = newQue();
    endQue(q, root);

    while (!isEmpty(q)) {
        const Node *current = delQue(q);
        printf("%d ", current -> data);
        if (current -> left) endQue(q, current -> left);
        if (current -> right) endQue(q, current -> right);
    }
}



int main() {
    Node *root = createNode(2);
    root -> left = createNode(3);
    root -> left -> right = createNode(3);
    root -> left -> left= createNode(4);
    root -> right = createNode(5);

    printf("PreOrder: ");
    preOrder(root);

    printf("\ninOrder: ");
    inOrder(root);

    printf("\nposOrder: ");
    posOrder(root);

    printf("\nlevelOrder: ");
    levelOrder(root);

}
