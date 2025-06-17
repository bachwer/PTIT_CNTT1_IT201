#include <stdio.h>

int main(){

    int n = 423;

    int sum = 0;

    //Cach 1
    //time Complexity: O(n)
    for(int i = 1; i <= n; i++) {
        sum += i;
    }


    printf("%d\n", sum);



    //Cach 2
    //time Complexity: O(1)
    sum =  n * (n + 1 ) /2; 
    printf("%d", sum);




}