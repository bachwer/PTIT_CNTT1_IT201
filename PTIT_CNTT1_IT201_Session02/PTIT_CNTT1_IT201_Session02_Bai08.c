#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for(int i = 0;i < n; i++){
        scanf("%d", &arr[i]);
    }


    for(int i = 0; i < n; i++){
        int check = 1;
        for(int j = i + 1; j < n; j++){
            if(arr[i] <= arr[j]){
                check = 0;
                break;
            }
        }
        if(check == 1){
            printf("%d ", arr[i] );
        }
        
    }

    



}