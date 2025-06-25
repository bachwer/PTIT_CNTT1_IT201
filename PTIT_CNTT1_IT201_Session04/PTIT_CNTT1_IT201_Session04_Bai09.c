#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void sort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
           if(arr[i] > arr[j]){
             swap(&arr[i], &arr[j]);
           }
        }
    }
}

int binaryS(int arr[], int n, int val){
    int left = 0;
    int right = n - 1;
  

    while(left <= right){
        int mid = left + (left + right) / 2;

        if(arr[mid] == val){
            printf("%d \n", mid);
            return mid;
        }else if(arr[mid] > val){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    printf("Khong ton tai 1");
    return -1;
}


int main(){
    int n, val;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));


    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    sort(arr, n);



    scanf("%d", &val);


    binaryS(arr, n, val);

    free(arr);

     


    












}
