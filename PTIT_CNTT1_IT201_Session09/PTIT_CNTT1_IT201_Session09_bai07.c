#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

typedef struct Node {
   int data;
   struct Node *next;
}Node;

Node* createNode(int val) {
   Node* new = (Node *)malloc(sizeof(Node));
   new -> data = val;
   new -> next = NULL;
   return  new;
}


void printNode(const Node* head) {
   if (head == NULL) {
      printf("NULL\n");
      return;
   }
   printf("%d -> ", head->data);
   printNode(head->next);
}



Node *addNode(Node* head, int val, int pos) {
   Node* temp = (Node*)malloc(sizeof(Node));
   temp -> data = val;
   if (pos == 1) {
      temp -> next = head;
      return temp;
   }

   Node* current = head;
   int i = 1;
   while (current != NULL && i < pos - 1) {
      current = current->next;
      i++;

   }

   if (current == NULL) {
      printf("Position Invalid");
      return head;
   }
   temp -> next = current -> next;
   current -> next =  temp;
   return head;

}





int main(){
   Node* head = NULL;
   Node* tail = NULL;
   for (int i = 1; i < 6; i++) {
      Node* newNode = createNode(i);

      if (head == NULL) {
         head = newNode;
         tail = newNode;
      }
      tail->next = newNode;
      tail = newNode;
   }

   printNode(head);

   int pos, val;
   printf("Enter position: "); scanf("%d", &pos);
   printf("Enter Value: "); scanf("%d", &val);
   head = addNode(head, val, pos);
   printNode(head);













   return 0;
}