//
// Created by Macbook on 04/07/2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(const int data) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

void printList(const Node *head) {
    if (head == NULL) {
        printf("NULL \n");
        return;
    }
    printf("%d <-> ", head -> data);
    printList(head -> next);
}

int main() {

    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < 5; i++) {
        Node *new = createNode(i + 1);
        if (head == NULL) {
            head = new;
            tail = new;
        }
        tail -> next = new;
        new -> prev = tail;
        tail = new;
    }

    printList(head);
    Node *temp = head -> next;
    temp -> prev = NULL;
    printList(temp);







}


