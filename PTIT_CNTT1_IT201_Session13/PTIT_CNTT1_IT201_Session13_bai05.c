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

Stack *createStack(int size) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s -> arr = (int *)malloc(size *sizeof(int));
    s -> top = -1;
    s -> maxSize = size;
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

void reverseArray(int *arr,int  n) {
    Stack *myS = createStack(n);
    for (int i = 0; i < n; i++) {
        push(myS, arr[i]);
    }
    for (int i = 0; i < n; i++) {
       arr[i] = pop(myS);
    }
}
void print(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

}


int main() {
    printf("Enter number Element in array: ");
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n *sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("%d: ", i + 1);
        scanf("%d", &arr[i]);
    }


    reverseArray(arr, n);
    print(arr, n);






}
