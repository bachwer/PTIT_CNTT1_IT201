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
    Stack *stack = (Stack *)malloc(sizeof(Stack));              // cấp phát vùng nhớ cho stack
    stack->arr = (int *)malloc(size * sizeof(int));             // cấp phát mảng động cho phần tử
    stack->top = -1;                                            // ban đầu rỗng
    stack->maxSize = size;                                      // gán kích thước tối đa
    return stack;                                               // trả về con trỏ stack
}

int isEmpty(const Stack *s) {
    return s -> top == -1;
}
int isFull(const Stack *s) {
    return s->top == s -> maxSize - 1;
}

void push(Stack* s, const int val) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s -> arr[++(s -> top)] = val;;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s -> arr[(s -> top)--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s -> arr[(s -> top)];
}

void printStack(const Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= s -> top; i++) {
        printf("%d ", s -> arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter element number: ");
    scanf("%d", &n);
    Stack *myStack = createStack(n);
    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        push(myStack, val);
    }

    printStack(myStack);
    printf("Top: %d\n",myStack -> top);
    printf("Cap: %d\n",myStack -> maxSize);


}
