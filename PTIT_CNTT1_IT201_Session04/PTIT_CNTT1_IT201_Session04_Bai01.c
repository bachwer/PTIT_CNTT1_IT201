#include <stdio.h>
#include <stdlib.h>


int main(){

    int n  = 0 ;
    int val;

    scanf("%d", &n);

    int* arr = (int *) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &val);


    for(int i = 0; i < n; i++){
        if(arr[i] == val){
            printf("%d", i);
            return 2;
        }

    }




    free(arr);








}