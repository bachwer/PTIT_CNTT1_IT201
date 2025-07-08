//
// Created by Macbook on 08/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int *arr;
    int top;
    int maxSize;
}Stack;
Stack *createStack(const int size) {
    Stack  *newStack = (Stack *)malloc(sizeof(Stack));
    newStack -> arr = (int *)malloc(size * sizeof(int));
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
void push(Stack *s, const int val) {
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

void printfs(Stack *num) {
   for (int i = 0; i < num -> top; i++) {
       printf("%d ", num -> arr[i]);
   }
    printf("\n");
}

void calculator(const char a, Stack *num) {
    const int b = pop(num);
    const int c = pop(num);

    if (a == '+') {
        push(num, c + b);

    }else if ( a == '-') {
        push(num, c - b);

    }else if (a == '*') {
        push(num, c * b);

    }
}



int postfix(char string[]) {
    int len = strlen(string);
    Stack *num = createStack(len);

    for (int i = 0; i < len; i++) {


        if (isdigit(string[i])) {

            push(num, string[i] - '0');

        }else {
            char a =string[i];

            if (num -> top < 0) {
                continue;
            }else if (num -> top > 0) {


                    calculator(a, num);
            }
        }

    }
    int result = 0;



    result += pop(num);

    return result;
}






int main() {


    const int n = postfix(" 231*+9-");
    printf("%d", n);

}
