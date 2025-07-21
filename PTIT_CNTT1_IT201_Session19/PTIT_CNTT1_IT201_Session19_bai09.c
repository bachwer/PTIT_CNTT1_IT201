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

Node *insertBST(Node *root, const int val) {
    if (root == NULL) return createNode(val);

    if (val < root -> data) {
        root-> left = insertBST(root -> left, val);
    }else if ( val > root -> data) {
        root-> right = insertBST(root -> right, val);

    }else {
    }
    return root;

}

void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


void freeTree(Node *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node *root = createNode(10);
    root -> left  =  createNode(5);
    root -> right = createNode(15);
    // root -> left -> left =  createNode(5);
    int values[] = {10, 5, 15, 3, 7, 12, 18, 5};
    int n = sizeof(values) / sizeof(values[0]);


    for (int i = 0; i < n; ++i) {
        root = insertBST(root, values[i]);
    }
    inorder(root);

    freeTree(root);

}
