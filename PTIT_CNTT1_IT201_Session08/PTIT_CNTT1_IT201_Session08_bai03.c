#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include <stdbool.h>
void printArray(const int *arr, const int n);

void Swap(int *a, int *b) {
   const int temp = *a;
   *a = *b;
   *b = temp;
}

// time complexity Best case: O(1)
//Worst case: O(n^2)
void BubbleSort(int *arr, const int n) {
   for (int i = 0; i < n - 1; i++) {
      bool check = false;
      for (int j = 0; j < n - 1 - i; j++) {
         if (arr[j] > arr[j + 1]) {
            Swap(&arr[j], &arr[j + 1]);
            check = true;
         }
      }
      if (!check) {
         break;
      }
   }
   printArray(arr, n);
}

void printArray(const int *arr, const int n) {
   for (int i = 0; i < n; i++) {

      printf("%d", arr[i]);


   }

}



int main(){

   int n;
   scanf("%d", &n);

   int *arr = (int *)malloc(n *sizeof(int));

   for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }


   BubbleSort(arr, n);



   return 0;
}