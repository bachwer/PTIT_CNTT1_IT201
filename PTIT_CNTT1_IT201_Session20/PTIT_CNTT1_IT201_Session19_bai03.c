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
    if (newQue != NULL) {
        newQue -> front = newQue -> rear = NULL;
    }
    return newQue;
}


void endQue(Queue *q,  Node *root) {
    if (root == NULL) return;
    QueueNode *newNode = malloc(sizeof(QueueNode));
    if (newNode == NULL) return;
    newNode -> data = root;
    newNode -> next = NULL;

    if (q -> front == NULL) {
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


void insertLevelOrder(Node *root, const int val) {
    if (root == NULL) return;
    Queue *q = newQue();
    endQue(q, root);

    while (!isEmpty(q)) {
        Node *current = delQue(q);

        if (current -> left == NULL) {
            current -> left = createNode(val);
            return;
        } else {
            endQue(q, current -> left);
        }

        if (current -> right == NULL) {
            current -> right = createNode(val);
            return;
        } else {
            endQue(q, current -> right);
        }
    }
}


void preOrder(const Node *root) {
    if (root == NULL) return;
    printf("%d ", root -> data);
    preOrder(root -> left);
    preOrder(root -> right);

}


int main() {
    Node *root = createNode(2);
    root -> left = createNode(3);
    root -> left -> right = createNode(3);
    root -> left -> left= createNode(4);
    root -> right = createNode(5);

    int val;
    printf("Nhap gia tri: ");
    scanf("%d", &val);

    insertLevelOrder(root, val);
    preOrder(root);



}


