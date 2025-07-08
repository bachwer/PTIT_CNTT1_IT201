//
// Created by Macbook on 08/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

bool checkString(char text[]) {
    const int len = strlen(text);

    Stack *str = createStack(len);

    for (int i = 0 ; i < len; i++) {
        int temp = text[i];
        if (temp == '(' || temp == '{' || temp == '[') {
            push(str, temp);
        }else {
            if ( str -> top < 0) {
                free(str);
                return false;
            }
            char last = str -> arr[(str -> top)--];

            if ((temp == ')' && last != '(')||
                (temp == ']' && last != '[')||
                (temp == '}' && last != '{')) {
                free(str);
                return false;
            }
        }



    }


    return str -> top == -1;

}





int main() {
    char text[100];
    char str[100];
    fgets(text, sizeof(text), stdin);
    text[strlen(text) - 1] = '\0';

    int index = 0;
    for (int i = 0; i < strlen(text); i++) {
       if ( (text[i] == '(' || text[i] == ')')||
            (text[i] == '{' || text[i] == '}')||
            (text[i] == '[' || text[i] == ']')) {
            str[index++] = text[i];

       }
    }
    str[index] = '\0';


    if (checkString(str)) {
        printf("True");
    }else {
        printf("False");
    }


}
