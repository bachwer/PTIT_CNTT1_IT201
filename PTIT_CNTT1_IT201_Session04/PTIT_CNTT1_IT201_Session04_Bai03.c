#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    scanf("%d", &n);
    int index = 0;


    int *arr = (int *)malloc(n * sizeof(int));

    int max = 100;
    for(int i = 0; i < n ; i++){
        scanf("%d", &arr[i]);

        if(max > arr[i] && max != arr[i]){
            max = arr[i];
            index = i;
            
        }
    }
    printf("%d", index);


   
    free(arr);

}