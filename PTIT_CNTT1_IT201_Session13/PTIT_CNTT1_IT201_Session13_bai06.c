//
// Created by Macbook on 08/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *arr;
    int top;
    int maxSize;
}Stack;
Stack *createStack(const int size) {
    Stack  *newStack = (Stack *)malloc(sizeof(Stack));
    newStack -> arr = (char *)malloc(size * sizeof(char));
    newStack -> top = -1;
    newStack -> maxSize = size;
    return newStack;
}
int isFull(const Stack *s) {
    return s -> top == s -> maxSize - 1;
}
int isEmpty(const Stack *s) {
    return s -> top == -1;
}
void push(Stack *s, const char val) {
    if (isFull(s)) {
        printf("Stack is full");
        return;
    }

    s -> arr[++(s -> top)] = val;
}


int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty");
        return - 1;
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

void symmetrical(char text[]) {
    if (strlen(text) == 0 || strlen(text) == 1) {
        printf("Invalid");
        return;
    }
    Stack *string = createStack(strlen(text));

    for (int i = 0; i < strlen(text); i++) {
        push(string, text[i]);
    }
    for (int i = 0; i < strlen(text) / 2; i++) {
        if (text[i] != pop(string)) {
            printf("False");
            return;
        }
    }
    printf("True");

}

int main() {
    char text[100];
    fgets(text, sizeof(text), stdin);
    text[strlen(text) - 1] = '\0';
    symmetrical(text);


}
