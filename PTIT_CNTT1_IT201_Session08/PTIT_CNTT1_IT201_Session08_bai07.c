#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void Swap(int *a, int *b) {
   const int temp = *a;
   *a = *b;
   *b = temp;
}


int partition(int *arr, const int left, const int right) {
   int pivot = arr[right];
   int i = left - 1;
   for (int j = left; j < right; j++) {
      if (arr[j] < pivot) {
         i++;
         Swap(&arr[i],&arr[j]);
      }
   }
   Swap(&arr[i + 1],&arr[right]);
   return (i + 1);
}

void quickSort(int *arr, int left, int right) {
   if (left < right) {
      int pi =  partition(arr, left, right);
      quickSort(arr, left, pi - 1);
      quickSort(arr, pi + 1, right);
   }

}






int main(){
   int n;
   scanf("%d", &n);
   int *arr =(int *)malloc(n * sizeof(int));
   for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }
   quickSort(arr, 0, n - 1);

   for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }





   return 0;
}