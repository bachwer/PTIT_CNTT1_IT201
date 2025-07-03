#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    int data;
    struct Node *next;
}Node;


Node *creatNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node*));
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}

void printNode(Node *head) {
    while (head == NULL) {
        printf("NULL\n");
        return;
    }

    printf("%d -> ", head->data);

    printNode(head -> next);


}

int main() {
    Node *head = NULL;
    Node *tail = NULL;

    int n;
    printf("Enter number Node :");
    scanf("%d", &n);

    for (int i = 0 ; i <  n; i++) {
        Node *newNode = creatNode(i + 1);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

    }
    printNode(head);




}
