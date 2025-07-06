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

Node *createNode(const int val) {
    Node *new = (Node *)malloc(sizeof(Node));
    new -> data = val;
    new -> next = NULL;
    new -> prev =  NULL;
    return new;
}

void printNode(Node *head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", head -> data);
    printNode(head -> next);
}




int main() {
    Node *head = NULL;
    Node *tail = NULL;
    int n ;
    printf("Enter Node number: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Node *new = createNode(i + 1);

        if (head == NULL) {
            head = new;
            tail = new;
        }
        tail -> next = new;
        new -> prev = tail;
        tail = new;
    }

    printNode(head);

    int val;
    scanf("%d", &val);

    Node *temp = createNode(val);
    temp -> next = head;

    printNode(temp);
}