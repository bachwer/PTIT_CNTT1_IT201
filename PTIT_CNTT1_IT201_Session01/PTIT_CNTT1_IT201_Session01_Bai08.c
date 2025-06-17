#include <stdio.h>




void findElement(int arr[], int n){
    int element[2000] = {0};

  
    //Time complexity: O(n)
    //Space complexity: O(n)
    
    for(int i = 0; i < n; i++){
        element[arr[i]]++;
    }

    int max = 0;
    int j = 0;




    for(int i = 0; i < n    ; i++){
        if(element[arr[i]] > max){
            max = element[arr[i]];
            j = i;
        }
    
    }
      printf("%d %d \n",arr[j],max );
  

    

}

int main(){

    int arr[] = {1,2,3,4,3,2,1,1,1,3,6,3,1,2,4};
    int n = sizeof(arr) / sizeof(int);
    findElement(arr, n);







}