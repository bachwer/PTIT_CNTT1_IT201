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
    if (newNode != NULL) {
        newNode -> data = data;
        newNode -> left = newNode -> right = NULL;
    }
    return newNode;
}





int preOrder(const Node *root, int val) {
    if (root == NULL) return -1;

    if (root -> data == val) {
        printf("True\n");
        return 1;
    }
    int leftResult = preOrder(root -> left, val);
    if (leftResult == 1) return 1;


    int rightResult = preOrder(root -> right, val);
    if (rightResult == 1) return 1;


    return -1;

}



int main() {
    Node *root = createNode(2);
    root -> left = createNode(3);
    root -> left -> left = createNode(5);
    root -> right = createNode(4);


    printf("Enter the number: ");
    int val; scanf("%d", &val);

    if (preOrder(root, val) == -1) {
        printf("False");
    }
    free(root);

}