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
    printf("%d", head -> data);
    if (head -> next != NULL) {
        printf(" <-> ");
    }else {
        printf(" -> ");
    }
    printNode(head -> next);
}

Node* removeNode(Node *head, const int val) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (head == NULL) {
        return NULL;
    }

    if (head -> data == val) {
        head = head -> next;
        free(temp);
        return removeNode(head, val);
    }
    head->next = removeNode(head->next, val);
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
            newNode -> prev -  tail;
            tail =  newNode;
        }
    }
    int val;
    printNode(head);
    printf("Value: ");
    scanf("%d", &val);
    head = removeNode(head, val);
    printNode(head);

}
