//
// Created by Macbook on 07/07/2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;


Node *createNode(const int val) {
    Node *new = (Node *)malloc(sizeof(Node));
    new -> data = val;
    new -> next = NULL;
    new -> prev = NULL;
    return new;
}

void printNode(Node *head) {
    if (head == NULL) {
        printf("NULL \n");
        return;
    }

    printf("%d", head -> data);

    if (head -> next != NULL) {

        printf(" <-> ");
    }else {
        printf(" -> ");
    }
    printNode(head -> next);
}

Node* removeNodeAtEnd(Node *head) {
    Node *temp = (Node *)malloc(sizeof(Node));

    Node *current = head;
    while (current -> next -> next != NULL) {
        current = current -> next;
    }
    temp = current -> next;
    current -> next = temp -> next;

    free(temp);

    return head;


}

int main() {

    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < 5; i++) {
        Node *newNode = createNode(i + 1);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }else{
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;

        }
    }

    printNode(head);
    head = removeNodeAtEnd(head);
    printNode(head);



}
