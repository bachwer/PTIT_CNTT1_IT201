#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void printArray(const int *arr, const int n) {

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);

    }

}

void SelectionSort(int *arr, const int n) {

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                arr[min] = arr[j];
            }
        }
        const int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;



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

    bubleSort(arr, n);

    free(arr);

    return 0;
}