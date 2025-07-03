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
void deleteNodeAtEnd(Node *head, int val, int n);


void deleteNodeAtEnd(Node *head, int val, int n) {
   if (val <= 0) {
       printf("Node: %d: %d", n + 1, head->data);
       return;
   }
    n++;
    deleteNodeAtEnd(head->next, val - 1, n);


}





int main() {

    Node *head = NULL;
    Node *tail = NULL;

    int n ;
    printf("Enter Number Node: ");
    scanf("%d", &n);

    for (int  i = 0 ; i < n; i++) {
        Node *newNode = createNode(i  + 1);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }

        tail -> next = newNode;
        tail = newNode;
    }

    printNode(head);
    deleteNodeAtEnd(head, n - 1, 0);













}