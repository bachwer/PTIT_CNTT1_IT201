#include <stdio.h>
#include <stdlib.h>




void check(int *arr, int k, int n){
    int count = 0;
    for(int i = 0; i < n; i++){

        if(arr[i] == k){
            count++;
        }

    }


     printf("%d", count);

}




int main(){

    int n;
    int numberCheck;
    scanf("%d", &n);
    scanf("%d", &numberCheck);
 
    int* arr = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }


    check(arr, numberCheck, n);



    


}
