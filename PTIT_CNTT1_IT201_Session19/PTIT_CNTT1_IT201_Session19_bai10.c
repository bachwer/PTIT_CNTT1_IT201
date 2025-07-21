//
// Created by Macbook on 21/07/2025.
//
//
// Created by Macbook on 21/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
bool isBST(Node *root, int min, int max) {
    if (root == NULL) return true;

    if (root->data <= min || root->data >= max) return false;

    return isBST(root->left, min, root->data) &&
           isBST(root->right, root->data, max);
}

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





int main() {
    Node *root = createNode(10);
    root -> left  =  createNode(5);
    root -> right = createNode(15);
    // root -> left -> left =  createNode(5);

    if (isBST(root, INT_MIN, INT_MAX)) {
        printf("true");
    }else {
        printf("false");
    }

    free(root);

}
