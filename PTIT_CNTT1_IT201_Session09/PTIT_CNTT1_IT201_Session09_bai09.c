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

   Node* newhead =  revertNode(head -> next);
   head -> next -> next = head;
   head->next = NULL;
   return newhead;
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