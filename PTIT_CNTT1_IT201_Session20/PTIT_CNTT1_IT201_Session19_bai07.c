//
// Created by Macbook on 22/07/2025.
//
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


void deLNode(Node *root, int val) {
    if (root == NULL) return;

    if (root -> left == NULL && root -> right ==NULL) {
        if (root -> data == val) {
            free(root);
            root = NULL;
        }else {
            printf("Ko ton tai\n");
        }
        return;
    }

    Queue *q = newQue();
    endQue(q, root);

    Node *tar = NULL;
    Node *cur = NULL;
    Node *parent =NULL;

    while (!isEmpty(q)) {
        cur = delQue(q);
        if (cur -> data == val) {
            tar = cur;
        }

        if (cur -> left) {
            parent = cur;
            endQue(q, cur-> right);
        }
        if (cur -> right) {
            parent = cur;
            endQue(q, cur-> left);
        }

    }
    if (tar == NULL) {
        printf("Ko ton tai\n");
        return;
    }
    tar -> data = cur -> data;
    if (parent -> right == cur) {
        free(parent -> right);
        parent -> right = NULL;
    }else if (parent -> left == cur) {
        free(parent -> left);
        parent -> left = NULL;
    }
    printf("Success!\n");
}

void levelOrder(Node *root) {
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
    int val;
    levelOrder(root);
    printf("\nNhap so can Xoa: ");
    scanf("%d", &val);
    deLNode(root, val);
    levelOrder(root);








}


