#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void Swap(int *a, int *b) {
    const int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int *arr, int n ) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }

}


// time complexity Best case: O(1)
//Worst case: O(n^2)
void InsertionSort(int *arr, int n) {

    for (int i = 1 ; i< n; i++) {
        const int key = arr[i];
        int j = i - 1;
        while ( j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    print(arr, n);

}






int main(){

    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n *sizeof(int));

    for (int  i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    InsertionSort(arr, n);




    return 0;
}