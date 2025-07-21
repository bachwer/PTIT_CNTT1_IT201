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

}QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
}Queue;

Queue *createQue() {
    Queue *newQue = malloc(sizeof(Queue));
    if (newQue != NULL) {
        newQue -> front = newQue -> rear = NULL;
    }
    return newQue;
}

bool isEmpty(Queue *q) {
    return q -> front == NULL;
}

void endQue(Queue *q, Node *node) {
    if (node == NULL) return;

    QueueNode *newNode = malloc(sizeof(QueueNode));
    if (newNode == NULL) return;

    newNode -> data = node;
    newNode -> next = NULL;
    if (q -> rear == NULL) {
        q -> front = q -> rear = newNode;
    }else {
        q -> rear -> next = newNode;
        q -> rear =newNode;
    }
}

Node *delQue(Queue *q) {
    if (isEmpty(q)) return NULL;
    QueueNode *temp = q -> front;
    Node *data = q -> front -> data;
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


void insertNodeLevel(Node *root, int val) {
    if (root == NULL) return;

    Queue *q = createQue();
    endQue(q, root);

    while (!isEmpty(q)) {
        Node *current = q -> front -> data;

        if (current -> left == NULL) {
            current -> left = createNode(val);
            break;
        }else {
            endQue(q, current -> left);
        }

        if (current -> right == NULL) {
            current -> right = createNode(val);
            break;
        }else {
            endQue(q, current -> right);
        }

        QueueNode *temp = q -> front;
        q -> front = q -> front -> next;
        free(temp);
        if (q -> front == NULL) q-> rear = NULL;

    }
    free(q);
}


void preOrder(const Node *node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}


int main() {
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    insertNodeLevel(root, 4);
    insertNodeLevel(root, 5);

    preOrder(root);

    free(root);
    return 0;
}
