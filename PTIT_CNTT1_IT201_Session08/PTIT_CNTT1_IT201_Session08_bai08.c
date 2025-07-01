#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
void binarySearch(int *arr, const int left, const int right, int target);
void linerSort(int *arr, int n, int target);
void printfArray(int *arr, int n) {
   for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");
}

void InsertionSort(int *arr, int n) {
   for (int i = 1;i < n; i++) {
      int key = arr[i];
      int j = i - 1;
      while (j >= 0 && arr[j] > key){
         arr[ j + 1] = arr[j];
         j--;
      }
      arr[j + 1] = key;
   }
   printfArray(arr, n);
   int val;
   printf("Enter value to Search: ");
   scanf("%d", &val);
   binarySearch(arr, 0, n - 1, val);
   linerSort(arr, n, val);

}


void binarySearch(int *arr, const int left, const int right, int target) {
   if (left >= right) {
      printf("Binary Sort index: invalid\n");
      return;
   }

   const int mid = left + (right - left) / 2;

   if (arr[mid] == target) {
      printf("Binary Sort index: %d\n", mid);
      return;
   }else if (arr[mid] < right) {
      binarySearch(arr, mid + 1, right, target);
   }else {
      binarySearch(arr, left, mid - 1, target);
   }
}

void linerSort(int *arr, int n, int target) {


   for (int i = 0 ; i < n; i++) {
      if (arr[i] == target) {
         printf("Liner Sort index: %d\n", i);
         return;
      }
   }

   printf("Liner Sort index: invalid\n");
}







int main(){

   int n;
   scanf("%d", &n);

   int *arr = (int *)malloc(n * sizeof(int));

   for (int  i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }
   InsertionSort(arr, n);


   return 0;
}