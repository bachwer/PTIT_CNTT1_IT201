#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include <stdbool.h>

void Swap(int *a, int *b) {
    const int temp = *a;
    *a = *b;
    *b = temp;
}
void binary(int *arr, int left, int right, int target) {

    if (left >= right) {
        printf("invalid");
        return;
    }

    const int mid =left + (right - left) / 2;

    if (arr[mid] == target) {
        printf("index: %d", mid);
        return;
    }else if (arr[mid] < target) {
        binary(arr, mid + 1, right, target );
    }else {
        binary(arr, left, mid - 1, target );
    }
}


void BubbleSort(int *arr, const int n, const int target) {
    for (int i = 0; i < n - 1; i++) {
        bool check = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                Swap(&arr[j], &arr[j + 1]);
                check = true;
            }
        }
        if (!check) {
            break;
        }
    }
    binary(arr, 0, n - 1, target);
}








int main(){

    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n *sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Target: ");
    scanf("%d", &target);
    BubbleSort(arr, n, target);




    return 0;
}