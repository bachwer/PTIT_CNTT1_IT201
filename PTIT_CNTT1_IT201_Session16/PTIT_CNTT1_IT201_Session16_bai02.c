#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
}Node;


typedef struct{
    Node *front;
    Node *rear;
}Queue;



Node *createNode(const int val) {
    Node *newNode = (Node *)malloc(sizeof(Queue));
    newNode -> data = val;
    newNode -> next = NULL;
    return newNode;
}

Queue *createQue() {
    Queue *newQue = (Queue *)malloc(sizeof(Queue));
    newQue -> front = newQue -> rear = NULL;
    return newQue;
}

int isEmpty(const Queue *q) {
    return q -> front == NULL;
}
void endQue(Queue *q, const int val) {
    Node *newNode = createNode(val);

    if (q -> front == NULL) {
        q -> front = q -> rear = newNode;
        return;
    }

    q -> rear -> next = newNode;
    q -> rear = newNode;
}

int delQue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    const int tempVal = q -> front -> data;
    Node *temp = q -> front;
    q -> front = q -> front -> next;
    free(temp);
    if ( q -> front == NULL) {
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

void printAllQueue(const Queue *q){
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    const Node *current = q -> front;
    while (current != NULL) {
        printf("%d -> ", current-> data);
        current = current -> next;
    }
    printf("NULL");
}
void freeQue(Queue *q) {
    while (isEmpty(q)) {
        delQue(q);
    }
    free(q);
}

int main() {
    Queue *q = createQue();
    int n;
    printf("Enter number element to add the queue: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("%d :", i+ 1);
        int val;
        scanf("%d", &val);
        endQue(q, val);
    }
    printAllQueue(q);
    freeQue(q);
    return 0;

}



