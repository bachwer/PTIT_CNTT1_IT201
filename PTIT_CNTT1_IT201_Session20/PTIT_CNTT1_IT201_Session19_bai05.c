//
// Created by Macbook on 22/07/2025.
//
//
// Created by Macbook on 22/07/2025.
//
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
int max = -1;
void prevOrder(const Node *root) {
    if (root == NULL) return;

    printf("%d", root -> data);
    if (max < root -> data) {
        max = root -> data;
    }
    prevOrder(root -> left);
    prevOrder(root -> right);
}





int main() {

    Node *root = createNode(2);
    root -> left = createNode(3);
    root -> left -> right = createNode(3);
    root -> left -> left= createNode(4);
    root -> right = createNode(5);

    prevOrder(root);

    printf("\nMAX:%d", max);


}


