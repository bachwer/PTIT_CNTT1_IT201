#include <stdio.h>
#include <stdlib.h>

int main(){

  int n = 5;
  int target;
  pritnf("Enter the value u want find: ");
  scanf("%d", &target);
  int *arr = (int *)malloc(n * sizeof(int));

  for(int i = 0; i < n; i++){
    scanf("%d ", &arr[i]);
  }

 for(int i = 0; i < n; i++){
  if(arr[i] == target){
    printf("Tim thay");
    return 0;
  }
 }

 printf("ko tim that");

  






}