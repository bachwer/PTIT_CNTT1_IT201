#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pow10(int n) {
    if (n == 0) return 1;
    return 10 * pow10(n - 1);
}


int stringToInt(char str[50], int index, int n){
    if(index == n){
        return 0;
    }

    int num = str[index]  - '0';

    return num * pow10(n - index - 1) +  stringToInt(str,index + 1, n);
}


int main(){
    char str[50];
    fgets(str, sizeof(str), stdin);
    str[strlen(str)  - 1] = '\0';

    int result = stringToInt(str, 0, strlen(str));
    printf("So nguyen: %d\n", result);








    return 0;
}