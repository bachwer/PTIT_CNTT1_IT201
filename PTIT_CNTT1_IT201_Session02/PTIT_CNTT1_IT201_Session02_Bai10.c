#include <stdio.h>
#include <stdlib.h>
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

    int n;
    scanf("%d", &n);
    int *num = (int *) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }

    
    // cach 1
    prinfNumber(num, n);

    // cach 2
    // Cach2(arr, n);

}



  









