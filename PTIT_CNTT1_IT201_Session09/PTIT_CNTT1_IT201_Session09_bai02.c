#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


typedef struct Node {
   int data;
   struct Node* next;
}Node;

Node* createNode(int val) {
   Node *newNode = (Node *)malloc(sizeof(Node));
   newNode -> data = val;
   newNode -> next = NULL;
   return newNode;
}


void printNode(const Node* head) {
   if (head == NULL) {
      printf("NULL");
      return;
   }
   printf("%d -> ", head->data);
   printNode(head->next);
}




int main(){
   Node* head = NULL;
   Node* tail = NULL;
   for (int i = 1; i < 6; i++) {

      printf("Node %d ->  ", i);
      int val;
      scanf("%d", &val);
      Node* newNode = createNode(val);
      if (head == NULL) {
         tail = newNode;
         head = newNode;
      }

      tail -> next = newNode;
      tail = newNode;
   }


   printNode(head);


   return 0;
}