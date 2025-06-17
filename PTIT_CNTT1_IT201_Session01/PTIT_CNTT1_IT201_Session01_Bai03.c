#include <stdio.h>
#include <stdlib.h>



 int* mallocArray(int n){

     int* arr = (int*) malloc(n* sizeof(int));
     // Time complexity: O(n)
     // Space complexity: O(n)
     for(int i = 0; i < n; i++){

         arr[i] =i;
         
     }
     return arr;
 }

int main(){


     int* arr = mallocArray(6);

     //Time complexity: O(n)
     for(int i = 0; i < 6; i++){
         printf( "%d", arr[i]);
     }







 }