#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


void printfibonacci(int n, int f1, int f2){

    if(n == 0){
        return;
    }
    printfibonacci(n - 1, f1 + f2 , f1);
    printf("%d ", f1 + f2);

}




int main(){
   int n;

   scanf("%d", &n);
    if (n == 0) {
        printf("0");
        return 0;
    }
    if (n == 1) {
        printf("%d", 1);
        return 0;
    }
    if (n == 2) {
        printf("%d", 1);
        return 0;
    }

    n -= 2;





   printfibonacci(n, 1, 1);
    printf("%d ", 1);
    printf("%d ", 1);








   return 0;
}