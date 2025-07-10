//
// Created by Macbook on 10/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[100][100];
    int front;
    int rear;
}Queue;

Queue* createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q -> front = q -> rear = -1;
    return q;

}

int isFull(const Queue *q) {
    return ((q -> rear + 1) % MAX == q -> front);
}
int isEmpty(Queue *q) {
    return(q -> front == - 1);
}

void enqueue(Queue *q, char name[]) {
    if (isFull(q)) {
        printf(".. is full\n");
        return;
    }
    if (isEmpty(q)) {
        q -> front = q -> rear = 0;
    }else {
        q -> rear = (q -> rear + 1) % MAX;
    }
    strcpy(q -> data[q -> rear], name);
}

char* dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("..Is Empty: ");
        return "0";
    }
    char *temp = q -> data[q -> front];
    if (q -> front == q -> rear) {
        q->front = q->rear = -1;
    }else {
        q -> front = ( q -> front + 1) % MAX;
    }
    return temp;
}








int main() {
    Queue * q = createQueue();

    for (int i = 0; i < 100; i++) {
        char temp[30];
        sprintf(temp, "%s %d", "customer", i + 1);
        enqueue(q,temp);
    }
    printf("First %s\n",dequeue(q));
    // printQ(q);

  free(q);

}


