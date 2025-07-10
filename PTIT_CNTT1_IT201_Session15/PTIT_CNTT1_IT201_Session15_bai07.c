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

Queue *createQueue(int size) {
    Queue* q = (Queue *)malloc(sizeof(Queue));
    q -> arr = (int *)malloc(size *sizeof(int));
    q -> front = 0;
    q -> rear = -1;
    q -> maxSize = size;
    return q;
}

int isEmpty(const Queue *q) {
    return (q -> front > q -> rear);
}
int isFull(const Queue *q) {
    return (q -> front == q ->maxSize - 1);
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q -> front = q -> rear = 0;
    }else {
        q -> rear = (q -> rear + 1) % q -> maxSize;
    }
    q -> arr[q -> rear] = value;
}

void printQueue(Queue *q) {
   for (int i = 0; i < q -> maxSize; i++) {
       printf("%d  ", q -> arr[i]);
   }
    int j = 0;
    for (int i = 0; i < q -> maxSize - 1; i++) {
        if (q -> arr[i + 1] != q -> arr[j++] + 1) {
            printf("\nFALSE");
            return;
        }
    }
    printf("\nTRUE");
}

void freeQue(Queue *q) {
    free(q -> arr);
    free(q);
}





int main() {

    printf("Enter Number element: ");
    int n; scanf("%d", &n);
    Queue *q = createQueue(n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(q, val);
    }


    printQueue(q);
    freeQue(q);
}












