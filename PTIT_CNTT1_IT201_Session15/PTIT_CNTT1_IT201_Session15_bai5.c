//
// Created by Macbook on 10/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int maxSize;
}Queue;

Queue *createQueue(const int size) {
    Queue* newQ = (Queue *)malloc(sizeof(Queue));
    newQ -> arr = (int *)malloc(size *sizeof(int));
    newQ -> front = newQ -> rear = -1;
    newQ -> maxSize = size;
    return newQ;
}

int isEmpty(Queue *q) {
    return q -> front == -1;
}
int isFull(Queue *q) {
    return ((q->rear + 1) % q->maxSize) == q->front;
}

void enqueue(Queue *q, const int val) {
    if (isFull(q)) {
        printf("is full\n");
        return;
    }

    if (isEmpty(q)) {
        q -> front = q -> rear = 0;
    }else {
        q -> rear =  (q -> rear + 1) % q -> maxSize;
    }
    q -> arr[q -> rear] = val;
}

int delQue(Queue *q) {
    if (isEmpty(q)) {
        printf("..Is empty");
        return - 1;
    }
    const int temp = q -> arr[q -> front];
    if (q -> front == q -> rear) {
         q -> front = q -> rear = -1;
    }else {
        q -> front =   q -> front + 1 % q -> maxSize;
     }
    return temp;
}

void freeQue(Queue *q) {
    free(q -> arr);
    free(q);
}



int main() {
    Queue *q = createQueue(5);
    for (int i = 0; i < 5; i++) {
        enqueue(q, i + 1);
    }
    printf("return: %d", delQue(q));
    freeQue(q)
}