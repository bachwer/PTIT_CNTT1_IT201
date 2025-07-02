#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

typedef struct Node {

   int data;
   struct Node *next;

}Node;


Node* createNode(int val) {
   Node *new = (Node *)malloc(sizeof(Node));
   new ->data = val;
   new -> next = NULL;
   return new;
}


void printNode(const Node *head) {
   if (head == NULL) {
      printf("NULL");
      return;
   }
   printf("%d ->", head->data);
   printNode(head -> next);
}



int main(){
   Node * head = NULL;
   Node *tail = NULL;
   for (int i = 0; i < 5; i++) {
      Node * newNode = createNode( i + 1);
      if (head == NULL) {
         head = newNode;
         tail = newNode;
      }
      tail -> next = newNode;
      tail = newNode;
   }
   printNode(head);



   printf("\n");

   Node *temp = head;
   head = temp->next;
   free(temp);

   printNode(head);











   return 0;
}