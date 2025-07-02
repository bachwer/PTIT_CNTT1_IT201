#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct Node {
   int data;
   struct Node * next;

}Node;


Node *createNode(int val) {
   Node * newNode = (Node *)malloc(sizeof(Node));
   newNode -> data = val;
   newNode -> next =NULL;
   return newNode;
}

void checkQuantity(Node *head, int index) {
   if (head == NULL) {
      printf("%d", index);
      return;
   }
   index++;
   checkQuantity(head->next, index);
}





int main(){
   Node* head = NULL;
   Node* tail = NULL;

   for (int i = 0; i < 9; i++) {
      int val;
      printf("Node %d ->", i + 1);
      scanf("%d", &val);
      Node *newNode = createNode(val);
      if (head == NULL) {
         head = newNode;
         tail =  newNode;
      }

      tail -> next = newNode;
      tail = newNode;
   }

   checkQuantity(head, 0);
   return 0;
}