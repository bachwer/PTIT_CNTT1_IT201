#include <stdio.h>
#include <stdlib.h>



void reverArray(int *arr, int n){

    for(int i = 0; i < n / 2 ; i++){
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }


 
}






int main(){

    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    
    for(int i = 0; i < n;i++){
        scanf("%d", &arr[i]);
    }

    reverArray(arr, n);







}