#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void Swap(int *a, int *b) {
   const int temp = *a;
   *a = *b;
   *b = temp;
}

void print(int *arr, int n ) {
   for (int i = 0; i < n; i++) {
      printf("%d", arr[i]);
   }

}


// time complexity Best case: O(1)
//Worst case: O(n^2)
void SelectionSort(int *arr, int n) {
   for ( int i = 0; i < n - 1; i++) {
      const int min = i;
      for (int j = i + 1; j < n; j++) {
         if (arr[j] < arr[min]) {
            Swap(&arr[j], &arr[min]);
         }
      }
      Swap(&arr[i], &arr[min]);
   }
   print(arr, n);

}






int main(){

   int n;
   scanf("%d", &n);
   int *arr = (int *)malloc(n *sizeof(int));

   for (int  i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

   SelectionSort(arr, n);




   return 0;
}