#include <stdio.h>
#include <stdlib.h>

int Recursion(int n, int i, int sum){

    if(i == n){
        printf("%d", sum);
        return sum;
    }else{
        i++;
        sum += i;
        Recursion(n, i, sum);
        
    }
    
}


int main(){

    int n;
    scanf("%d", &n);
    Recursion(n, 0, 0);
    



}