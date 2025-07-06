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
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = val;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    return newNode;
}

void printNode(Node *head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", head -> data);
    printNode(head->next);
}

void searchNode(Node *head, const int val) {

    if (head == NULL) {
        printf("FALSE");
        return;
    }

    if (head ->data == val) {
        printf("True");
        return;
    }


    searchNode(head -> next, val);
}



int main() {
    Node *head = NULL;
    Node *tail = NULL;


    for (int i =0; i < 5; i++) {
        Node *new = createNode(i + 1);

        if (head == NULL) {
            head = new;
            tail = new;
        }
        tail -> next = new;
        new -> prev = tail;
        tail = new;
    }
    printf("Value: ");
    int val;
    printNode(head);
    scanf("%d", &val);



    searchNode(head, val);

}