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
void sortListAscending(Node *head) {
    if (head == NULL) return;

    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {

                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }

        lptr = ptr1;

    } while (swapped);
}





int main() {

    Node *head = NULL;
    Node *tail = NULL;
    // Bachqvsb24Dtcn077
    int n ;
    printf("Enter Number Node: ");
    scanf("%d", &n);

    for (int  i = 0 ; i < n; i++) {
        Node *newNode = createNode(n - i);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }

        tail -> next = newNode;
        tail = newNode;
    }
    Bachqvsb24Dtcn077

    printNode(head);
    sortListAscending(head);
    printNode(head);













}