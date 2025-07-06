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


Node* createNode(int val) {
    Node* newNode = (Node* )malloc(sizeof(Node));
    newNode->data = val;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}


void printList(Node *head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }

    printf("%d <-> ", head -> data);
    printList(head -> next);
}

Node* addNode(Node *head, const int val, const int pos) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (pos <= 1) {
        temp = head;
        temp -> data = val;
        return temp;
    }

    Node* current = head;
    int i = 0;
    while (current != NULL && i < pos - 2) {
       current = current -> next;
        i++;

        if (current == NULL) {
            printf("Invalid\n");
            return head;
        }
    }
    temp -> data = val;
    temp -> next = current -> next;
    current -> next = temp;
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
        }else {
            tail -> next = newNode;
            newNode -> prev= tail;
            tail = newNode;
        }
    }




    printList(head);
    int val, pos;

    printf("Enter your value: ");
    scanf("%d", &val);
    printf("Enter your position: ");
    scanf("%d", &pos);
    head = addNode(head, val, pos);
    printList(head);






}