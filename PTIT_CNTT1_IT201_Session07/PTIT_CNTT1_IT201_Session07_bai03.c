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

    for (int i = 0; i < n   ; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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