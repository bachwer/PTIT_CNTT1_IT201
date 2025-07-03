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

Node * addNodeAtEnd(const int val, Node *head) {
    Node *temp = createNode(val);

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
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

    int val;
    scanf("%d", &val);


    head = addNodeAtEnd(val, head);

    printNode(head);













}