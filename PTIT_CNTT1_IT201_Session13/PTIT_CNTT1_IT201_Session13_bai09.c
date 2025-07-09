#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct {
    int *arr;
    int top;
    int maxSize;
}Stack;

char string[1000] = "";


Stack *createStack(const int size) {
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    newStack -> arr = (int  *)malloc(size *sizeof(int));
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

void push(Stack *s, const int val) {
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
char String[10][100];
int i = 0;

void connectString(const int a, const int b, const char pun) {
    char temp[100];

    if (a != -1 && b != -1) {
        sprintf(temp, "(%d %c %d)", b, pun, a);
        strcpy(String[i++], temp);
    } else {

        char left[100], right[100];

        if (b == -1 && i > 0) {
            strcpy(left, String[--i]);
        } else {
            sprintf(left, "%d", b);
        }

        if (a == -1 && i > 0) {
            strcpy(right, String[--i]);
        } else {
            sprintf(right, "%d", a);
        }

        sprintf(temp, "(%s %c %s)", left, pun, right);
        strcpy(String[i++], temp);

    }
}


















    //
    // if (strlen(string) == 0) {
    //     strcpy(string, temp);
    // }else if (a != -1 && b != -1) {
    //     char temp1[20];
    //
    //     strcpy(temp1, string);
    //     sprintf(string, "(%s %c %s)",temp1, pun ,temp);
    //
    // }else {
    //     strcpy(temp, string);
    //     sprintf(string, "(%s %c %d)",temp, pun ,a );
    // }






void calculator(const char pun, Stack *str) {
    const int a = pop(str);
    const int b = pop(str);
    connectString(a, b, pun);

}






void postfix(char text[]) {
    const int len = strlen(text);
    Stack *str = createStack(len);

    for (int i = 0; i < len; i++) {

        if (isdigit(text[i])) {
            push(str, text[i] - '0');
        }else {
            calculator(text[i],str);

        }
    }
}












int main() {
    char text[] = "231*+9-";
    // char text[] = "24+46+*";
    postfix(text);
    printf("%s\n", String[0]);
}






















