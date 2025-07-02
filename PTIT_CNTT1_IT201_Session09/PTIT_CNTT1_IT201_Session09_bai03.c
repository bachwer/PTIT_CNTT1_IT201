#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

typedef struct Node {
   int data;
   struct Node* next;
}Node;

Node* createNode(int val) {
   Node* newNode = (Node *)malloc(sizeof(Node));
   newNode -> data = val;
   newNode -> next = NULL;
   return newNode;
}

void SearchNode(Node *head, int val) {
   if (head == NULL) {
      printf("False");
      return;
   }

   if (head->data == val) {
      printf("True");
      return;
   }






   SearchNode(head->next, val);
}



int main(){
   Node *head = NULL;
   Node *tail = NULL;

   for (int i = 0; i < 5; i++) {
      int val;
      printf("Node %d -> ", i + 1);
      scanf("%d",&val);
      Node * newNode = createNode(val);

      if (head == NULL) {
         head = newNode;
         tail = newNode;
      }
      tail -> next = newNode;
      tail =  newNode;
   }
   int val;
   printf("Val: ");
   scanf("%d", &val);
   SearchNode(head,val);




   return 0;
}