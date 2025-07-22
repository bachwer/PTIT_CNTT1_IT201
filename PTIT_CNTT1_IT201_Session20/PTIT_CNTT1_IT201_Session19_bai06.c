//
// Created by Macbook on 22/07/2025.
//

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
typedef struct QueueNode {
    Node *data;
    struct QueueNode* next;
}QueueNode;
typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
}Queue;

Queue *newQue() {
    Queue *q = malloc(sizeof(Queue));
    if (q != NULL) {
        q -> front = q -> rear = NULL;
    }
    return q;
}

int isEmpty(const Queue *q) {
    return q -> front == NULL;
}

void endQue(Queue *q, Node *node) {
    if (node == NULL) return;

    QueueNode *newNode = malloc(sizeof(QueueNode));
    if (newNode == NULL) return;

    newNode -> data = node;
    newNode -> next = NULL;

    if (q -> front == NULL) {
        q -> front = q -> rear = newNode;
    }else {
        q -> rear -> next = newNode;
        q -> rear = newNode;
    }

}

Node *delQue(Queue *q) {
    if (isEmpty(q)) {
        return NULL;
    }
    QueueNode *temp = q -> front;
    Node *data = q -> front -> data;
    q -> front = q -> front -> next;
    if ( q -> front == NULL) q -> rear = NULL;
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

int findLevel(Node *root, const int val) {
    if (root == NULL) return - 1;
    Queue *q = newQue();
    endQue(q, root);

    int level = 1;
    while (!isEmpty(q)) {
        int size = 0;
        const QueueNode *temp = q -> front;
        while (temp != NULL) {
            size++;
            temp = temp -> next;
        }

        for (int i = 0; i < size; i++) {
            const Node *current = delQue(q);
            if (current -> data == val) {
                return level;
            }

            if (current -> left) endQue(q, current -> left);
            if (current -> right) endQue(q, current -> right);

        }
        level++;
    }

    return -1;

}





int main() {

    Node *root = createNode(2);
    root -> left = createNode(3);
    root -> left -> right = createNode(3);
    root -> left -> left= createNode(4);
    root -> right = createNode(5);

    printf("Nhap so can tim: ");
    int val; scanf("%d", &val);

    int n = findLevel(root, val);
    printf("Level: %d", n);





}


