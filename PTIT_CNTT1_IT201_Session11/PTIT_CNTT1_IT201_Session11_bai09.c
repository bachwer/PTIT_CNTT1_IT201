//
// Created by Macbook on 04/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;


Node *createNode(int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
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

    printf("%d -> ", head ->data);

    printNode(head -> next);
}

Node *reverseList(Node *head) {
    if (head == NULL || head -> next == NULL) {
        return head;
    }
    Node *newHead = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return newHead;
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
        new -> prev =  tail;
        tail = new;
    }
    printNode(head);
    head = reverseList(head);
    printNode(head);




}