#include <stdio.h>




void sum(int n, int temp) {
    if(n == 0){
        printf("%d", temp);
        return;
    }
    temp += n % 10;
    n /= 10;
    sum(n, temp);

}



int main() {
    int n ;
    scanf("%d",&n);
    sum(n, 0);
}