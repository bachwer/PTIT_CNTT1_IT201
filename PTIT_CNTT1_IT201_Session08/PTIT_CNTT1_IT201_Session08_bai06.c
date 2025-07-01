#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>



// best Case: O(n log n)
// worst Case: O(n log n)

void mSort(int *arr, const int left, const int mid, const int right) {
   const int n1= mid - left + 1;
   const int n2= right - mid;
   int L[n1], R[n2];

   for (int i = 0; i < n1; i++) {
      L[i] = arr[left + i];
   }
   for (int i = 0; i < n2; i++) {
      R[i] = arr[mid + 1 + i];
   }
   int i = 0; int j = 0; int k = left;

   while (i < n1 && j < n2) {
      if (L[i] <= R[i]) {
         arr[k] = L[i];
         i++;
      }else {
         arr[k] = R[j];
         j++;
      }
      k++;
   }

   while (i < n1) {
      arr[k] = L[i];
      i++;
      k++;
   }

   while (j < n2) {
      arr[k] = R[j];
      j++;
      k++;
   }
}

void recursive(int *arr, int left, int right) {

   if (left < right) {
      int mid = left + (right - left) / 2;
      recursive(arr, left, mid);
      recursive(arr, mid + 1, right);
      mSort(arr, left, mid, right);
   }

}










int main(){

   int n;
   scanf("%d", &n);
   int *arr = (int *)malloc(n * sizeof(int));

   for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

   recursive(arr, 0, n - 1);

   for (int i = 0 ; i < n; i++) {
      printf("%d", arr[i]);
   }






   return 0;
}