#include <stdio.h>
#include <stdlib.h>

int sum(int arr[],int n, int sum1){
    if(n < 0){
        printf("%d", sum1);
        return sum1;
    }
    sum1 += arr[n];
    sum(arr, n - 1, sum1);

}




int main(){
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    sum(arr, n, 0);







    return 0;
}