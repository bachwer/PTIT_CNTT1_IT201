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

Node *removeNode(Node *head, int pos) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (pos == 1) {
        head = head->next;
        free(temp);
        return head;
    }

    Node *current = head;
    int i = 0;
    while (current != NULL && i < pos - 1) {
        current = current -> next;
        i++;
    }

    temp = current -> next;
    current->next = temp->next ;
    free(temp);
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
        }
        tail -> next = new;
        new -> prev =  tail;
        tail = new;
    }
    printNode(head);
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    head = removeNode(head, pos);
    printNode(head);




}