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
        printf("Error");
        return NULL;
    }
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

void posOrder(const Node *root) {
    if (root == NULL) return;

    posOrder(root -> left);
    posOrder(root -> right);
    printf("%d ", root -> data);
}

int main() {
    Node *r = createNode(2);
    r -> right =  createNode(4);
    r -> left = createNode (3);

    r -> left -> left = createNode(5);



    posOrder(r);
    free(r);

}