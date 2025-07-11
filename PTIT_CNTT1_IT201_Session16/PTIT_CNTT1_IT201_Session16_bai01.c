
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node *front;
    Node *rear;
}Queue;

Node *createNode(const int val) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = val;
    newNode -> next = NULL;
    return newNode;
}

Queue *createQueue() {
    Queue *newQue = (Queue *)malloc(sizeof(Queue));
    newQue -> front = NULL;
    newQue -> rear = NULL;
    return newQue;
}

int isEmpty(const Queue *q) {
    return q -> front == NULL;
}

void endQue(Queue *q, const int val) {
    Node *temp = createNode(val);
    if (q -> front == NULL) {
        q -> front = q -> rear = temp;
        return;
    }
    q -> rear -> next = temp;
    q -> rear = temp;
}


int delQue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return - 1;
    }
    const int tempVal = q -> front -> data;
    Node *temp = q->front;
    q -> front = q -> front -> next;
    free(temp);

    if (q -> front == NULL) {
        q -> rear = NULL;
    }
    return tempVal;
}


int peek(const Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return q -> front -> data;
}

void freeQue(Queue *q) {
    while (isEmpty(q)) {
        delQue(q);
    }
    free(q);
}



int main() {
    Queue *que = createQueue();
    if (que == NULL) {
        return 1;
    }
    endQue(que, 10);
    endQue(que, 20);
    endQue(que, 30);

    printf("%d\n", peek(que));
    printf("%d\n", delQue(que));
    printf("%d\n", peek(que));

    freeQue(que);


}















