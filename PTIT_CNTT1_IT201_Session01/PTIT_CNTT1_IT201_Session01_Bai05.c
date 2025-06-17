#include <stdio.h>





int main(){


    int arr[10] = {2,3,4,1,2,5,7,8,3,1};
    int n = sizeof(arr) / sizeof(arr[0]);


    //Time complexity = O(n * n)
    for(int i = 0; i < n + 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }

    }


    for(int i = 0; i < 10; i++){
        printf("%d", arr[i]);
    }


}