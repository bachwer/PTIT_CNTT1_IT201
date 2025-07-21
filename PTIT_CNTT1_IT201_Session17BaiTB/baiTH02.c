//
// Created by Macbook on 15/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct {
    char *number;
    char *time;
}Num;



typedef struct Node {
    Num num;
    struct Node *next;
}Node;

typedef struct {
    Node *front;
    Node *rear;
}Queue;


typedef struct {
    Node *top;
}Stack;


Node *createNode(const char number[],const char time[]) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }

    newNode -> num.number = (char *)malloc(strlen(number) *sizeof(char));
    newNode -> num.time = (char *)malloc(strlen(time) *sizeof(char));

    strcpy(  newNode -> num.number, number);
    strcpy(  newNode -> num.time, time);
    newNode -> next = NULL;
    return newNode;
}



//stack
Stack *createStack() {
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    newStack -> top =NULL;
    return newStack;
}


void push(Stack *s,const char num[], const char time[]) {
    Node *newNode = createNode(num, time);
    if (newNode == NULL) {
        return;
    }
    newNode -> next = s -> top;
    s -> top = newNode;
}


int isEmpty(const Stack *s) {
    return s == NULL;
}


Num pop(Stack *s) {
    if (isEmpty(s)) {
        Num result;
        result.number = "NULL";
        result.time = "NULL";
        return result;
    }

    Node *temp = s->top;
    s->top = temp->next;


    Num result;
    result.number = strdup(temp->num.number);
    result.time = strdup(temp->num.time);

    free(temp->num.number);
    free(temp->num.time);
    free(temp);
    return result;
}

// Queue

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL) {
        return 0;
    }
    q -> front = q -> rear = NULL;
    return q;
}



Queue *enqueue(Queue *q, const char num[], const char time[]) {
    Node *newNode =(Node *)malloc(sizeof(Node));
    newNode -> num.number = (char *)malloc(strlen(num)*sizeof(char));
    newNode -> num.time = (char *)malloc(strlen(time)*sizeof(char));
    newNode -> next = NULL;
    strcpy(newNode -> num.number, num);
    strcpy(newNode -> num.time, time);


    if (q -> rear == NULL) {
        q -> front = q -> rear = newNode;
        return q;
    }

    q -> rear -> next = newNode;
    q -> rear = newNode;
    return q;
}

char* getTime() {
    static char buffer[10];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    strftime(buffer, sizeof(buffer), "%H:%M:%S", t);
    return buffer;
}

// CALL: gọi 1 số mới → lưu vào Stack và Queue
void callNumber(Stack *number, Queue *history, Stack**forwardStack);
// BACK: quay lại số trước đó → di chuyển qua Stack khác
void backNumber(Stack *number, Stack *forwardStack);
// REDIAL: gọi lại số tiếp theo nếu có
void redialNumber(Stack *number, Stack *forwardStack,Queue *history);

// HISTORY: hiển thị toàn bộ số đã gọi
void printHistory(const Queue *history);
// EXIT: thoát chương trình

void freeNode(Stack *s) {
    while (s->top != NULL) {
        pop(s);
    }
    free(s);
}



void dequeue(Queue *q) {
    if (q -> front == NULL) {
        return;
    }
    Node *temp = q -> front;
    q -> front = q -> front -> next;
    if (q -> front == NULL) {
        q -> rear = NULL;
    }
    free(temp);
}

void freeQueue(Queue *q) {
    while (q -> front != NULL ) {
        dequeue(q);
    }
    free(q);
}

int main() {
    Stack *number = createStack();
    Stack *forwardStack = createStack();
    Queue *history = createQueue();

    int choice;

    do {
        printf("---------MENU---------------\n");
        printf("1. CALL: gọi 1 số mới → lưu vào Stack và Queue\n");
        printf("2. BACK: quay lại số trước đó → di chuyển qua Stack khác\n");
        printf("3. REDIAL: gọi lại số tiếp theo nếu có\n");
        printf("4. HISTORY: hiển thị toàn bộ số đã gọi\n");
        printf("5. EXIT: thoát chương trình\n");
        printf("Moi nhap y/c: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                callNumber(number, history, &forwardStack);
                break;
            case 2:
                backNumber(number,forwardStack);

                break;
            case 3:
                redialNumber(number, forwardStack, history) ;
                break;
            case 4:
                printHistory(history);
                break;
            case 5:
                freeNode(number);
                freeNode(forwardStack);
                freeQueue(history);

                break;
            default: ;
        }

    }while (choice != 5);
}





// logic function
void callNumber(Stack *number, Queue *history, Stack**forwardStack) {
    char numberPhone[20];
    char time[10];
    strcpy(time, getTime());

    printf("Nhap so dien thoai: ");
    getchar();
    fgets(numberPhone, sizeof(numberPhone), stdin);
    numberPhone[strlen(numberPhone) - 1] = '\0';

    push(number, numberPhone, time);
    *forwardStack = createStack();
    enqueue(history, numberPhone, time);

}


void printHistory(const Queue *history) {
    if (history == NULL || history -> front == NULL) {
        printf("Queue is empty ");
        return;
    }
    Node *temp = history -> front;
    int i = 1;
    printf("------ History List -------- \n");
    while ( temp != NULL) {
        printf("|%d. Time: %8s  |numberPhone: %12s |\n", i++ , temp ->num.time, temp ->num.number);
        temp = temp -> next;
    }

}



void backNumber(Stack *number, Stack *forwardStack) {
    if (number -> top -> next == NULL) {
        printf("Không có cuộc gọi nào trước đó.!!\n");
        return;
    }
    const Num temp = pop(number);
    if (temp.number == "NULL" || temp.time == "NULL") {
        printf("Không có cuộc gọi nào trước đó.!!\n");
        return;
    }else {
        printf("|Time: %8s  |numberPhone: %12s |\n", temp.time, temp.number);
        push(forwardStack,temp.number, temp.time);
    }
    printf("Success !!\n");
}




void redialNumber(Stack *number, Stack *forwardStack, Queue *history) {
    if (forwardStack -> top  == NULL) {
        printf("Không có cuộc gọi nào trước đó.!!\n");
        return;
    }
    const Num temp = pop (forwardStack);
    if (temp.number ==  "NULL" || temp.time == "NULL") {
        printf("Không có cuộc gọi nào trước đó.!!\n");

        return;
    }
    printf("|Time: %8s  |numberPhone: %12s |\n", temp.time, temp.number);
    push(number, temp.number, temp.time);
    enqueue(history,temp.number, getTime());
}














