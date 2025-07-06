//
// Created by Macbook on 04/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;


Node* createNode(const int val) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = val;
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

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    int n;

    printf("Enter node number: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Node *newNode = createNode(i+ 1);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }


    printNode(head);


}