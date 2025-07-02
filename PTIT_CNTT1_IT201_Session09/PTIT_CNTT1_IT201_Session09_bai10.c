#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
}Node;



Node* createNode(int val) {
    Node* new =  (Node *)malloc(sizeof(Node));
    new ->data = val;
    new -> next = NULL;
    return new;
}
void printNode(Node* head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", head->data);
    printNode(head -> next);
}





Node* revertNode(Node *head) {
    if (head == NULL || head -> next == NULL) {
        return head;
    }

    Node *prve = NULL;
    Node *current = head;
    head = head -> next;

    while (current != NULL && current -> next != NULL) {
        Node * next = current -> next ->next;
        Node * second = current -> next;

        second -> next = current;
        current -> next = next;

        if (prve !=  NULL) {
            prve -> next= second;
        }
        prve = current;
        current = next;
    }
    return head;

}







int main(){

    Node *head = NULL;
    Node * tail = NULL;

    for (int i = 1; i < 6; i++) {
        Node * new = createNode(i);

        if (head == NULL) {
            head = new;
            tail = new;
        }
        tail -> next = new;
        tail = new;
    }

    printNode(head);


    Node * temp = NULL;
    temp = revertNode(head);
    printNode(temp);


    return 0;
}