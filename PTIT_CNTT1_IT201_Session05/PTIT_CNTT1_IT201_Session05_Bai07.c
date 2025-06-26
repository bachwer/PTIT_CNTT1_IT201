#include <stdio.h>
#include <stdlib.h>



int fibonacci(int arr[],int f1,int f2,int n, int index){
    if(index == n){
        return 0;
    }
    const int fn = f1 + f2;
    arr[index] = fn;

    fibonacci(arr, fn, f1, n, index + 1);

}



int main(){
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    if(n == 0){
        printf("%d", 0);
    }
    if(n <= 2){
        printf("%d", 1);
    }

    fibonacci(arr, 1, 1, n, 3);

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}