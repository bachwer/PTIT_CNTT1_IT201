#include <stdio.h>
#include <stdlib.h>

void Recursion(int n, int i){

    if(i == n){
        return;
    }else{
        i++;
        printf("%d ", i);
        Recursion(n, i);
        
    }
    
}


int main(){

    int n;
    scanf("%d", &n);
   
    Recursion(n, 0);



}