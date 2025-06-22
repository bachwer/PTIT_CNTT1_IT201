#include <stdio.h>
#include <stdlib.h>



void printElement(int *arr, int n){

    for(int i = 0; i < n; i++){

        printf("index: %d; value: %d \n", i + 1 , arr[i]);

    }



}


int main(){


    int n;

   
    scanf("%d", &n);
     if( n < 1){
        return 0;
    }
    int *arr = (int *) malloc(n * sizeof(int));


    for(int i = 0;i < n; i++){
        scanf("%d", &arr[i]);
    }


    printElement(arr, n);

    

}