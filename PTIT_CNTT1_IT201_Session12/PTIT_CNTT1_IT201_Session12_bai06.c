//
// Created by Macbook on 07/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;


Node* createNode(int val) {
    Node *new = (Node *)malloc(sizeof(Node));
    new -> data = val;
    new -> next = NULL;
    new -> prev = NULL;
    return new;
}

int printList(Node *head, int length) {
    if (head == NULL) {
        printf("NULL\n");
        return length;
    }


    printf("%d", head -> data);

    if (head -> next != NULL) {
        printf(" <-> ");
    }else{
        printf(" -> ");
    }

    return printList(head -> next, length + 1);


}

int findNode(Node *head, int pos) {
    int i = 0;
    while (head != NULL  && i <= pos - 1) {
        head = head -> next;
        i++;
    }

    printf("Node %d: %d\n", i + 1, head -> data);
}



int main() {
    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < 6; i++) {
        int val;
        printf("Node %d: ", i + 1);
        scanf("%d", &val);
        Node *newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }else {
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }

    const int length = printList(head, 0) / 2.0;
    findNode(head, length);

}
