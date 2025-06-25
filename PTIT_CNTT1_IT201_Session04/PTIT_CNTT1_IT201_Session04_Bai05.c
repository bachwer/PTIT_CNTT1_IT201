#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));


    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }


    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

        int val;
    scanf("%d", &val);
    int left = 0;
    int right = n - 1;


    while( left <= right){

        int mid = left + (right - left) / 2;

        if(arr[mid] == val){
            printf("%d", mid);
             free(arr);
            return 1;
        }else if(val < arr[mid]){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }


    printf("phan tu ko ton tai");

    free(arr);

}

