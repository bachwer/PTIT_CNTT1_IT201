//
// Created by Macbook on 21/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(const int data) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error\n");
        return NULL;
    }
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

void preOrder(const Node *root) {
    if (root == NULL) return;

    printf("%d ", root -> data);
    preOrder(root -> left);
    preOrder(root -> right);
}


int main() {

    Node *r = createNode(2);
    Node *r1 = createNode(3);
    Node *r2 = createNode(5);
    Node *r3 = createNode(4);

    r -> left = r1;
    r -> right = r3;
    r1 -> left = r2;





    preOrder(r);
    free(r);

}