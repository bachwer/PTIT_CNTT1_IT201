#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int val;
    scanf("%d", &val);
    int check = -1;

     for(int i = 0; i < n; i++){
       if(val == arr[i]){
        printf("%d", i);
        check = 1;
       }
    }

    if(check == - 1){
        printf("Khong ton taj");
    }


    free(arr);


}