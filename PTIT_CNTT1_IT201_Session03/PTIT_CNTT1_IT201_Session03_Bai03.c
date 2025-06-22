#include <stdio.h>
#include <stdlib.h>



void printElement(int *arr, int n){

    int max = 0;
    int count = 0;
   for(int i = 0; i < n; i++){
        if(arr[i] % 2 == 0){
            max += arr[i];
            count++;
        }

   }

   printf("Max: %d", max / count);


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