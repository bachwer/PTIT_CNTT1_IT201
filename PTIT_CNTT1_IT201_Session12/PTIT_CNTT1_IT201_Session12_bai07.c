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

Node* sort(Node *head) {
    if (head == NULL || head -> next == NULL) {
        return head;
    }
    int swapped;
    Node *ptr1;
    Node *ptr2 = NULL;
      do {
          swapped = 0;
          ptr1 = head;
          while (ptr1 -> next != ptr2) {
              if (ptr1 -> data > ptr1 -> next -> data ) {
                  int temp = ptr1 -> data;
                  ptr1 -> data = ptr1 -> next -> data ;
                  ptr1 -> next -> data = temp;
                  swapped = 1;
              }
              ptr1 = ptr1 -> next;
          }
          ptr2 = ptr1;
      }while (swapped != 0);
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
    printNode(head);
    head = sort(head);
    printNode(head);

}
