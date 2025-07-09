//
// Created by Macbook on 09/07/2025.
//
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node *top;
}Stack;

Node *createNode(const int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = val;
    newNode -> next = NULL;
    return newNode;
}
Stack *createStack(const int size) {
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    newStack -> top = NULL;
    return newStack;
}

void push(Stack *s, const int val) {
    Node *newNode = createNode(val);
    newNode -> next = s -> top;
    s -> top = newNode;
}

int pop(Stack *s) {
    const int val = s -> top -> data;
    Node *temp = s -> top;
    s -> top = s -> top -> next;
    free(temp);
    return val;
}
void printList(const Node *head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", head ->data);
    printList(head -> next);
}


int main() {
    Stack *note = createStack(5);
    printf("Enter number note to add in Stack: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i< n; i++) {
        int m;
        printf("Note %d: ", i + 1);
        scanf("%d", &m);
        push(note, m);
    }

    if (note -> top != NULL) {
        printList(note -> top);
    }else {
        printf("List note is empty");
    }


}
