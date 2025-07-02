#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


typedef struct Node {
   int data;
   struct Node  *next;
}Node;


Node* creatNode(int val) {
   Node* new = (Node *)malloc(sizeof(Node));
   new -> data = val;
   new -> next = NULL;
   return new;

}

void printNode(const Node *head) {
   if (head == NULL) {
      printf("NULL");
      return;
   }
   printf("%d -> ", head->data);
   printNode(head->next);
}

Node* removeNode(Node* head, int pos) {
   Node* temp = (Node* )malloc(sizeof(Node));
   if (pos == 1) {
      temp = head -> next;
      return temp;
   }

   Node* current = head;
   int i = 1;
   while (current != NULL && i < pos - 1){
      current = current -> next;
      i++;
   }

   temp = current -> next;
   current -> next = temp -> next;

   return head;

}





int main(){
   Node *head = NULL;
   Node* tail = NULL;

   for (int i = 1; i < 6;i++) {
      Node* new =  creatNode(i);
      if (head == NULL) {
         head = new;
         tail = new;
      }
      tail -> next  = new;
      tail = new;
   }
   printNode(head);

   printf("\n");
   printf("Enter index: ");
   int pos;
   scanf("%d", &pos);

   head = removeNode(head, pos);
   printNode(head);




   return 0;
}