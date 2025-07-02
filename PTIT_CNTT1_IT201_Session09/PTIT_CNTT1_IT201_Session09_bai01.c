#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


typedef struct Node {
   int data;
   struct Node* next;

}Node;


Node * createNode(int value) {
   Node *head = (Node *)malloc(sizeof(Node));
   if (head == NULL) {
      exit(1);
   }
   head -> data = value;
   head -> next = NULL;
   return head;
}

void printfNode(Node * head) {
   if (head == NULL) return;

   printf("Node %d\n", head->data);
   printfNode(head -> next);

}




int main(){
   Node *head = NULL;
   Node* tail = NULL;
   for (int i = 0; i < 5; i++) {
      Node* newNode = createNode(i + 1);
      if (head == NULL){
         head = newNode;
         tail = newNode;
      }
      tail -> next = newNode;
      tail = newNode;
   }


   printfNode(head);


   free(head);


   return 0;
}