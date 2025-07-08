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


Stack createStack(int size) {
    Stack s;
    s.arr = (int *)malloc(size *sizeof(int));
    s.top = -1;
    s.maxSize = size;
    return s;
}
int isEmpty(const Stack *s) {
    return s -> top == -1;
}

int isFull(const Stack *s) {
    return s->top == s -> maxSize -1;
}



void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full");
        return;
    }
    s -> arr[++(s -> top)] = value;
}
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("stack is empty");
    }
    int value = s -> arr[(s -> top)--];
    return value;
}
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("stack is empty");
        return -1;
    }
    return s -> arr[s -> top];
}

void printStack(const Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty");
        return;
    }
    for (int i = 0; i <= s -> top; i++) {
        printf("%d", s -> arr[i]);
    }
    printf("\n");
}
int main() {
    Stack myStack = createStack(5);
    push(&myStack, 1);
    push(&myStack, 2);
    push(&myStack, 3);
    push(&myStack, 4);
    push(&myStack, 5);


}
