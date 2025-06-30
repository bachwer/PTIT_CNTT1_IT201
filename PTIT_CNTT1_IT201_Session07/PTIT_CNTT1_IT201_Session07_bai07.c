#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void swap(int *a, int *b) {
   const int temp =*a;
   *a = *b;
   *b = temp;
}


int partition(int *arr, int l, int r) {
   int pivot = arr[r];
   int i = l - 1;


   for (int j = l; j < r; j ++) {
      if (arr[j] < pivot) {
         i++;
         swap(&arr[i], &arr[j]);
      }
   }
   swap(&arr[i + 1], &arr[r]);
   return ( i + 1);
}

int quickSort(int *arr, int l, int r) {
   if (l < r) {
      const int pi = partition(arr, l, r);
      quickSort(arr, l, pi - 1);
      quickSort(arr, pi + 1, r);

   }
   return 0;

}

void printArray(const int *arr, int n) {
   for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");
}




int main(){

   int n;
   scanf("%d", &n);

   int *arr = (int  *)malloc(n *sizeof(int));

   for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

   quickSort(arr, 0, n - 1);
   printArray(arr, n);


   free(arr);

   return 0;
}