//
// Created by Macbook on 03/07/2025.
//


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;


Node * createNode(int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = val;
    newNode -> next = NULL;
    return newNode;
}

void printNode(Node * head) {
    if (head  == NULL) {
        printf("NUll\n");
        return;
    }

    printf("%d -> ", head -> data );
    printNode(head -> next);

}

Node* deleteNodeAtEnd(Node *head, int val) {
    if (head == NULL) return NULL;

    Node *current = head;
    Node *target = NULL;
    Node *targetPrev = NULL;
    Node *prev = NULL;

    while (current != NULL) {
        if (current->data == val) {
            targetPrev = prev;
            target = current;
        }
        prev = current;
        current = current->next;
    }


    if (target == NULL) return head;

    if (target == head) {
        head = head->next;
        free(target);
        return head;
    }

    targetPrev->next = target->next;
    free(target);

    return head;
}





int main() {

    Node *head = NULL;
    Node *tail = NULL;

    for (int  i = 0 ; i < 5; i++) {
        Node *newNode = createNode(i  + 1);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }

        tail -> next = newNode;
        tail = newNode;
    }

    printNode(head);

    head = deleteNodeAtEnd(head, 2);
    printNode(head);













}