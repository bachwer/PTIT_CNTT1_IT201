#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void printArray(const int *arr, const int n) {

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);

    }

}

void bubleSort(int *arr, const int n, const int x) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0 ; j < n - i - 1; j++) {

            if (abs(x - arr[j]) > abs(x -arr[j + 1])) {
                const int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }


        }

    }

    printArray(arr, n);
}








int main(){

    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n *sizeof(int));

    for (int i = 0; i< n ; i++) {
        scanf("%d", &arr[i]);
    }

    printf("X: ");
    int x;
    scanf("%d", &x);

    bubleSort(arr, n, x);


    free(arr);


    return 0;
}