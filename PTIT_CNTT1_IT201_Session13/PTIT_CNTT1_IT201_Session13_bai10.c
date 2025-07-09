#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char *arr;
    int top;
    int maxSize;
}Stack;

char string[1000] = "";


Stack *createStack(const int size) {
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    newStack -> arr = (char  *)malloc(size *sizeof(char));
    newStack -> top = -1;
    newStack -> maxSize = size;
    return newStack;
}

int isFull(Stack *s) {
    return s -> top == s -> maxSize -1;
}
int isEmpty(Stack *s) {
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
        return - 1;
    }
    return  s->arr[(s->top)--];
}




char String[100] ="";
int i = 0;

void addStr(const char val) {
    String[i++] = val;
}


void infixToPostfix(char text[]) {
    const int len = strlen(text);
    Stack *pun = createStack(len);

    for (int i = 0; i < len; i++) {
        if (text[i] == '+'||
            text[i] == '-'||
            text[i] == '*') {
            push(pun, text[i]);
        }else if (text[i] == ')' ) {
            while (pun -> top != -1) {
                addStr(pop(pun));
            }
        }else {
           if (text[i] == '(') continue;
            addStr(text[i]);
        }
    }

    while (pun -> top != -1) {
        addStr(pop(pun));
    }
}




int main() {
    // char text[] = "234+-";
    // char text[] = "24+46+*";
    // char text[] = "231*+9-";
    infixToPostfix("(2+4)*(4+6)");
    printf("%s", String);

}






















