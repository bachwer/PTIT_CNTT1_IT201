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
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* current = head;

    while (current != NULL && current->next != NULL) {
        Node* nextNode = current->next;
        Node* prevNode = current->prev;
        Node* nextNext = nextNode->next;


        if (prevNode != NULL) {
            prevNode->next = nextNode;
        } else {
            head = nextNode;
        }

        nextNode->prev = prevNode;
        nextNode->next = current;

        current->prev = nextNode;
        current->next = nextNext;

        if (nextNext != NULL) {
            nextNext->prev = current;
        }


        current = current->next;
    }

    return head;
}

int main() {

    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < 5; i++) {
        Node *new = createNode(i + 1);
        if (head == NULL) {
            head = new;
            tail = new;
        }else {
            tail -> next = new;
            new -> prev =  tail;
            tail = new;
        }

    }



    printNode(head);
    head = reverseList(head);
    printNode(head);




}