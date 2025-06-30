#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


void mSort(int *arr, int left, int mid, int right) {
   int n1 = mid - left + 1;
   int n2 = right - mid;

   int L[n1], R[n2];

   for (int i = 0; i < n1; i++) {
      L[i] = arr[left + i];
   }
   for (int i = 0; i < n2; i++) {
      R[i] = arr[mid + 1 + i];
   }

   int i = 0, j = 0, k = left;

   while (i < n1 && j < n2 ){
      if (L[i] <= R[j]  ) {
         arr[k] = L[i];
         i++;
      }else {
         arr[k] = R[j];
         j++;
      }
      k++;
   }

   while ( i < n1) {
      arr[k] = L[i];
      i++;
      k++;
   }

   while (j < n2) {
      arr[k] = R[j];
      k++;
      j++;
   }
}

void Sort(int *arr, int left, int right) {

   if (left < right){
      int mid = left + (right  - left) / 2;
      Sort(arr, left, mid);
      Sort(arr, mid + 1, right);
      mSort(arr, left, mid, right);
   }
}

void printArray(int arr[], int size) {
   for (int i = 0; i < size; i++)
      printf("%d ", arr[i]);
   printf("\n");
}




int main(){
   int n;
   scanf("%d", &n);
   int *arr = (int *)malloc(n * sizeof(int));

   for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

   Sort(arr, 0, n - 1);
   printArray(arr, n);




   free(arr);


   return 0;
}