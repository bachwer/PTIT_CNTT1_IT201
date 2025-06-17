#include <stdio.h>

void printDoulble(int n){
    int i = 1;

    while(i < n){
        printf("%d ", i);
        i *= 2;
    }


}


int main(){

    //time complexity: O(log n)
    //explan: vì vòng lặp while chỉ chạy n / 2
    printDoulble(10);
}