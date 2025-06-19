#include <stdio.h>
#include <stdlib.h>


int main(){

    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    for(int i = 0; i  < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Nhap vi tri can sua: " );
    int pos;

    scanf("%d", &pos);
    if(pos > n){
        printf("Invalid!!");
        return 0;
    }
    printf("Nhap gia tri: ");

    scanf("%d", &arr[pos - 1]);


      for(int i = 0; i < n; i ++){
        printf("%d ", arr[i]);

    }




}