#include <stdio.h>

void prinfNumber(int arr[], int n){
     int count[2000];
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

int main(){

    int arr[] = {1,2,3,4,20,1,3,4,20};
    int n = sizeof(arr) / sizeof(arr[0]);
    prinfNumber(arr, n);
   

}



  









