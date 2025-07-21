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

    printf("%d - ", root -> data);
    preOrder(root -> left);
    preOrder(root -> right);
}
int main() {
    Node *root = createNode(2);
    root -> left  =  createNode(3);
    root -> right = createNode(4);
    root -> left -> left =  createNode(5);

    preOrder(root);

    free(root);

}
