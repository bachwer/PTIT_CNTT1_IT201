//
// Created by Macbook on 04/07/2025.
//

#include <stdio.h>
#include <stdlib.h>



typedef struct Node {
    int data;
    struct Node * next;
    struct Node * prev;
}Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

void printNode(Node *head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d <-> ", head -> data);
    printNode(head -> next);
}




int main(){
    Node *node1 = createNode(10);
    Node *node2 = createNode(11);
    Node *node3 = createNode(12);
    Node *node4 = createNode(13);
    Node *node5 = createNode(14);

    node1 -> next = node2;
    node2 -> prev = node1;

    node2 -> next = node3;
    node3 -> prev = node2;

    node3 -> next = node4;
    node4 -> prev = node3;

    node4 -> next = node5;
    node5 -> prev = node4;

    printNode(node1);

}