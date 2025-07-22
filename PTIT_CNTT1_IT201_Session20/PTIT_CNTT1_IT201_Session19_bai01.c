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

Node *createNode(const int data) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode -> data = data;
        newNode -> left = newNode -> right = NULL;
    }
    return newNode;
}

void prevOrder(const Node *root) {
    if (root == NULL) return;

    printf("%d", root -> data);
    prevOrder(root -> left);
    prevOrder(root -> right);
}





int main() {
    int n;
    printf("Node: ");
    scanf("%d", &n);

    Node *root = createNode(n);
    root -> left = createNode(4);
    root -> right = createNode(5);

    prevOrder(root);


}


