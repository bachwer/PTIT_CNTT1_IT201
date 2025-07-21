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

Node* addNodeAtEnd(Node *head, const int val) {
    if (head -> next ==  NULL) {
        Node *temp = createNode(val);
        head -> next = temp;
        temp -> prev = head;
        return head;
    }
    addNodeAtEnd(head -> next, val);
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
    int val;
    printf("Enter value: ");
    scanf("%d", &val);
    addNodeAtEnd(head, val);
    printNode(head);



}


void selectionSort(Node* head) {
    Node* current = head;

    while (current != NULL) {
        Node* minNode = current;
        Node* nextNode = current->next;

        while (nextNode != NULL) {
            if (nextNode->data < minNode->data) {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }

        // Hoán đổi dữ liệu
        if (minNode != current) {
            int temp = current->data;
            current->data = minNode->data;
            minNode->data = temp;
        }

        current = current->next;
    }
}
