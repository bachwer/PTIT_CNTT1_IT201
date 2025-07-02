#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

typedef struct Node {
   int data;
   struct Node *next;
}Node;


Node* createNode(int val) {
   Node* newNode = (Node *)malloc(sizeof(Node));
   newNode -> data = val;
   newNode -> next = NULL;
   return newNode;
}

void printNode(const Node* head) {
   if (head == NULL) {
      printf("NULL");
      return;
   }

   printf("%d - >", head->data);

   printNode(head -> next);
}


int main() {
   Node *head = NULL;
   Node *tail = NULL;

   for (int i = 1; i < 6; i++) {
      int val;
      printf("Node %d ->", i);
      scanf("%d", &val);
      Node* newNode = createNode(val);

      if (head == NULL) {
         head = newNode;
         tail = newNode;
      }
      tail -> next = newNode;
      tail = newNode;
   }


   printf("Enter the value to add at the start: ");
   int val;
   scanf("%d", &val);


   Node* newNode = createNode(val);
   newNode -> next =head;
   head = newNode;


   printNode(head);








   return 0;
}