#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void search(int *arr, int n, int target) {
   for (int i = 0; i < n; i++) {
      if (target == arr[i]) {
         printf("%d ", i);
         return;
      }
   }

   printf("invalid");

}




int main(){
   int n;
   scanf("%d ", &n);
   int *arr = (int *)malloc(n * sizeof(int));

   for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }



   int t;
   printf("Value: ");

   scanf("%d", &t );
   search(arr, n, t);





   return 0;
}