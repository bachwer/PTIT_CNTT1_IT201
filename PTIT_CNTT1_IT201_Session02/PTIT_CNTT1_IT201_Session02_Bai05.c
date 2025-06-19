#include <stdio.h>
#include <stdlib.h>


int main(){

    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    for(int i = 0; i  < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Nhap vi tri can xoa: " );
    int pos;

    scanf("%d", &pos);
    if(pos > n){
        printf("Invalid!!");
        return 0;
    }

    for(int i = pos - 1; i < n; i ++){
        arr[i] = arr[i + 1];
    }

    n--;

      for(int i = 0; i < n; i ++){
        printf("%d ", arr[i]);

    }




}