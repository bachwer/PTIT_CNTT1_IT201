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
    for (int i = 0; i< 5; i++) {
        push(note, i + 1);
    }
    printList(note -> top);
    printf("Enter value to add in Stack: ");
    int val;
    scanf("%d", &val);
    push(note,val );
    printList(note -> top);
}
