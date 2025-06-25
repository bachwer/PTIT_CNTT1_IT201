#include <stdio.h>
#include <stdlib.h>

int main(){


    int n,m;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for(int i = 0 ; i < n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &m);

    int index = 0;
    int check = - 1;

     for(int i = 0 ; i < n; i++){
        if(m == arr[i]){
            index = i;
            check = 1;
        }
    }

    


   if(check == 1){
        printf("%d", index);
   }else{
     printf("ko thay");
   }


   free(arr);
  






}