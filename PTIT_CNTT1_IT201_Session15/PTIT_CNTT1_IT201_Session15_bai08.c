//
// Created by Macbook on 10/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    int age;
    char *name;
    struct Node *next;
}Node;


typedef struct {
    Node *front;
    Node *rear;
}Queue;


Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q -> front = q -> rear = NULL;
    return q;
}


Node *enqueue(Queue *q, const int age, const char name[]) {
    Node *newNode =(Node *)malloc(sizeof(Node));
    newNode -> name = (char *)malloc(strlen(name)*sizeof(char));
    newNode -> age = age;
    newNode -> next = NULL;
    strcpy(newNode -> name, name);
    if (q -> rear == NULL) {
        q -> front = q -> rear = newNode;
        return newNode;
    }
    q -> rear -> next = newNode;
    q -> rear = newNode;

    return newNode;

}

void dequeue(Queue *q) {
    if (q -> front == NULL) {
        printf("Queue is Empty: ");
        return;
    }
    Node *temp = q -> front;
    int age = temp -> age;
    char *name = temp->name;
    q -> front = q -> front -> next;
    if (q -> front == NULL) {
        q ->rear = NULL;
    }
    free(temp);
}

int isEmpty(const Queue *q) {
    return (q -> front == NULL);
}


void freeQueue(Queue *q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}


void printProgress(Queue *Fir, Queue *Sec) {
    int index = 1;
    while (!isEmpty(Fir)) {
        printf("Progress %d: %d - ",index++, Fir -> front -> age );
        printf("%s \n ", Fir -> front -> name );
        dequeue(Fir);
    }

    printf("-------");

    while (!isEmpty(Sec)) {
        printf("Progress %d: %d - ",index++, Sec -> front -> age );
        printf("%s \n ", Sec -> front -> name );
        dequeue(Sec);
    }
    printf("\n -Done-");
}



void addCustomer( const int age, const char text[],Queue *oldCus, Queue *NorCus ) {
    if (age >= 60) {
        enqueue(oldCus, age, text);
    }else {
        enqueue(NorCus,age, text);
    }

};


int main() {
    int numCus;
    Queue *oldCus = createQueue();
    Queue *NorCus = createQueue();

    printf("Enter number customer of bank: ");
    scanf("%d", &numCus);
    for (int i = 0; i < numCus; i++) {
        char name[100];
        int age;
        printf("-- Customer %d --\n", i + 1);
        printf("Enter Customer age  : ");
        scanf("%d", &age);
        getchar();

        printf("Enter Customer name: ");
        fgets(name, sizeof(name), stdin);
        name[strlen(name) - 1] = '\0';

        addCustomer(age, name,oldCus, NorCus);
    }

    printProgress(oldCus,NorCus);


    freeQueue(oldCus);
    freeQueue(NorCus);
}






