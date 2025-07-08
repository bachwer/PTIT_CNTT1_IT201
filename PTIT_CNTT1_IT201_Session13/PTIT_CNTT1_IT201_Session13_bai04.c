//
// Created by Macbook on 08/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int top;
    int maxSize;
}Stack;

Stack *createStack(const int size) {
    Stack *myStack = (Stack *)malloc(sizeof(Stack));
    myStack -> arr = (int *)malloc(size * sizeof(int));
    myStack -> top = -1;
    myStack -> maxSize = size;
    return myStack;
}
int isFull(const Stack *s) {
    return s -> top == s -> maxSize - 1;
}
int isEmpty(const Stack * s) {
    return s -> top == -1;
}
void push(Stack *s, const int val) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s -> arr[++(s -> top)] = val;
}

void printStack(const Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = s -> top; i >= 0; i--) {
        printf("%d ", s -> arr[i]);
    }
}
int main() {
    Stack *myStack = createStack(5);
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    push(myStack, 40);
    push(myStack, 50);
    printStack(myStack);
}

