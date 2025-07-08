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
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    newStack -> arr = (int *)malloc(size * sizeof(int));
    newStack -> top = -1;
    newStack -> maxSize = size;
    return newStack;
}
int isEmpty(const Stack *s) {
    return s -> top == -1;
}
int isFull(const Stack *s) {
    return s -> top ==s -> maxSize - 1;
}

void push(Stack *s, const int val) {
    if (isFull(s)) {
        printf("Stack is full");
        return;
    }
    s -> arr[++(s -> top)] = val;
}

int pop (Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty");
        return -1;
    }

    return s -> arr[(s->top)--];
}





int main() {
    Stack *myS = createStack(5);
    push(myS, 1);
    push(myS, 2);
    push(myS, 3);
    printf("%d", pop(myS));

}
