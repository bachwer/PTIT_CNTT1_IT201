#include <stdio.h>

void prinfNumber(int arr[], int n){
     int count[2000] = {0};
     //Time complexity: O(n)
     //Space complexity: O(n)
    for(int i = 0; i < n; i++){
         count[arr[i]]++;
    }

    for(int i = 0; i < n; i++){
        if(count[arr[i]] > 0){
            printf("%d %d \n", arr[i], count[arr[i]]);
            count[arr[i]] = 0;
        }
        
    }
}

void Cach2(int arr[], int n){

    //Time complexity: O(n * n)
    //Space complexity: O(n * n)
    for(int i = 0; i < n; i++){
        int count = 1;
        for(int j = i + 1; j < n; j++){
            if(arr[i] == arr[j]){
                count++;
                arr[j] = -1;
            }
        }
       if(arr[i] != -1)  printf("%d %d \n", arr[i], count);

    }
}


int main(){

    int arr[] = {1, 1230, 3, 4, 1230, 1, 3, 4, 20, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    
    // cach 1
    prinfNumber(arr, n);

    // cach 2
    Cach2(arr, n);

}



  









