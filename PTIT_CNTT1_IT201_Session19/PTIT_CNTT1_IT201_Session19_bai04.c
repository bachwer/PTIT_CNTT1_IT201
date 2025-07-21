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
        printf("NULL\n");
        return NULL;
    }
    newNode -> data = data;
    newNode -> right = newNode -> left = NULL;
    return newNode;
}

void inOrder(const Node *root) {
    if (root == NULL) return;

    inOrder(root -> left);
    printf("%d ", root -> data);
    inOrder(root -> right);

}




int main() {
    Node *root = createNode(2);
    root -> left = createNode(3);
    root -> left -> left = createNode(5);
    root -> right = createNode(4);

    inOrder(root);
    free(root);




}