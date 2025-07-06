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


Node * createNode(int val) {
    Node *new = (Node *)malloc(sizeof(Node));
    new -> data = val;
    new -> next = NULL;
    new -> prev = NULL;
    return new;
}

void printList(Node *head) {
    if (head == NULL) {
        printf("NULL");
        return;
    }
    printf("%d -> ", head->data);
    printList(head -> next);
}

int getLengthList(const Node *head,int n ) {
    if (head == NULL) {
        return n;
    }
    n++;
    getLengthList(head->next, n);
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


    printf("Node %d", getLengthList(head, 0));







}