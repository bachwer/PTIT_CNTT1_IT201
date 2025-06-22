#include <stdio.h>
#include <stdlib.h>




int main(){


    int n;

   
    scanf("%d", &n);
     if( n < 1){
        return 0;
    }
    int *arr = (int *) malloc(n * sizeof(int));


    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int *temp = (int *) realloc(arr, (n + 2) * sizeof(int));

    printf("Them 2 phan tu: \n");
    
   for(int i = n; i < n + 2; i++){
        scanf("%d", &temp[i]);
    }


      for(int i = 0; i < n + 2; i++){
       printf("%d", temp[i]);
    }
    

    free(arr);




    

}