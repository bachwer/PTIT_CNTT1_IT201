//
// Created by Macbook on 15/07/2025.
//
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char *number;
    char *time;
}Subject;
typedef struct Node {
    Subject phone;
    struct Node *next;
    struct Node *prev;
}Node;



typedef struct {
    Node * top;
}Stack;

Node *createNode(const char *number, const char *time) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error");
        return NULL;
    }
    newNode -> phone.number = (char *)malloc(strlen(number) *sizeof(char));
    newNode -> phone.time = (char *)malloc(strlen(time) *sizeof(char));
    strcpy(newNode -> phone.number, number);
    strcpy(newNode -> phone.time, time);
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

Stack *createStack() {
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    newStack -> top = NULL;
    return newStack;
}



// stack
void push(Stack *stack, const char *number, const char *time ) {
    Node *newNode = createNode(number, time);
    if (newNode == NULL) {
        printf("failed to push\n");
        return;
    }
    newNode -> next = stack -> top;
    stack -> top = newNode;
}


Subject pop(Stack *stack) {

    if (stack == NULL) {
        Subject results;
        printf("Empty\n");
        results.number = strdup("NULL");
        results.time = strdup("NULL");
        return results;

    }

    Node *temp = stack -> top;
    stack -> top = temp -> next;

    Subject results;
    results.number = strdup(temp->phone.number);
    results.time = strdup(temp->phone.time);


    free(temp -> phone.time);
    free(temp -> phone.number);
    free(temp);

    return results;
}

// queue;
void endQue(Queue *q, const char *number, const char* time) {
    Node *newNode = createNode(number, time);
    if (newNode == NULL) {
        printf("Error\n");
        return;
    }

    if (q -> rear == NULL) {
        q -> front = q -> rear = newNode;
        return;
    }

    q -> rear -> next = newNode;
    q -> rear = newNode;

}

char* getTime() {
    static char buffer[10];
    const time_t now = time(NULL);
    const struct tm *t = localtime(&now);

    strftime(buffer, sizeof(buffer), "%H:%M:%S", t);
    return buffer;
}

// CALL: gọi 1 số mới → lưu vào Stack và Queue
void functionCall(Stack *number, Queue *history, Stack **forwardStack);
// BACK: quay lại số trước đó → di chuyển qua Stack khác
void functionBack(Stack *number, Stack *forwardStack);
// REDIAL: gọi lại số tiếp theo nếu có
void functionRedtail(Stack *number, Stack *forwardStack, Queue *history);
// HISTORY: hiển thị toàn bộ số đã gọi
void functionHistory(const Queue *history);
// EXIT: thoát chương trình
void functionFreeStack(Stack *s);
void functionFreeQueue(Queue *q);





int main(){
    Stack *number = createStack();
    Stack *forwardStack =createStack();
    Queue *history = createQue();
    int choice;
    do {
        printf("|======== MENU =======|\n");
        printf("|  1. CALL       \n");
        printf("|  2. BACK       \n");
        printf("|  3. REDIAL    \n");
        printf("|  4. HISTORY    \n");
        printf("|  5. EXIT     \n");
        printf("|======== END  =======|\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                functionCall(number,history, &forwardStack);
                break;
            case 2:
                functionBack(number, forwardStack);
                break;
            case 3:
                functionRedtail(number,forwardStack, history);
                break;
            case 4:
                functionHistory(history);
                break;
            case 5:
                printf("Exited !!!!\n");
                functionFreeStack(number);
                functionFreeStack(forwardStack);
                functionFreeQueue(history);
                break;
            default: ;
        }





    }while (choice != 5);


}

// CALL: gọi 1 số mới → lưu vào Stack và Queue
void functionCall(Stack *number, Queue *history, Stack **forwardStack) {
    char string[20];
    char time[10];
    strcpy(time, getTime());

    printf("Enter the phone number: ");
    getchar();
    fgets(string, sizeof(string), stdin);
    string[strlen(string) - 1]= '\0';
    push(number, string, time);

    *forwardStack = createStack();
    endQue(history, string, time);
}






// BACK: quay lại số trước đó → di chuyển qua Stack khác
void functionBack(Stack *number, Stack *forwardStack) {
    if (number -> top ==  NULL || number -> top ==  NULL ) {
        printf("Không có cuộc gọi nào trước đó!!\n");
        return;
    }
    if (number -> top -> next == NULL) {
        printf("Không có cuộc gọi nào trước đó!!\n");
        return;
    }

    const Subject temp = pop(number);

    if (strcmp(temp.number, "NULL") == 0 || (strcmp(temp.time, "NULL") == 0)) {
        printf("Không có cuộc gọi nào trước đó!!\n");
        return;
    }else {
        printf("|Time: %8s  |numberPhone: %12s |\n", temp.time, temp.number);
        push(forwardStack, temp.number, temp.time);
    }

    printf("Success !!");

}


// REDIAL: gọi lại số tiếp theo nếu có
void functionRedtail(Stack *number, Stack *forwardStack, Queue *history) {
    if (forwardStack -> top == NULL) {
        printf("is Empty!!\n");
        return;
    }

    const Subject temp = pop(forwardStack);

    if (strcmp(temp.number, "NULL") == 0 || (strcmp(temp.time, "NULL") == 0)) {
        printf("Không có cuộc gọi nào trước đó!!\n");
        return;
    }else {
        printf("|Time: %8s  |numberPhone: %12s |\n", temp.time, temp.number);
        push(number, temp.number, temp.time);
        endQue(history, temp.number, getTime());
    }

    printf("Success !!");







}
// HISTORY: hiển thị toàn bộ số đã gọi
void functionHistory(const Queue *history){
    if (history -> front == NULL) {
        printf("List is empty!!\n");
        return;
    }

    const Node *current = history -> front;


    int  i = 1;
    printf("|------------------------History List------------------|\n");
    while (current  != NULL) {

        printf("|%d: Phone number: %15s - Time: %10s |\n", i++, current ->phone.number ,current ->phone.time);


        current = current -> next;
    }
    printf("|----------------------------- END ------------------|\n");

}




// EXIT: thoát chương trình

void functionFreeStack(Stack *s) {
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


void functionFreeQueue(Queue *q) {
    while (q -> front != NULL ) {
        dequeue(q);
    }
    free(q);
}





