#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool check(char str[], int n, int i){

    if(n < 1){
         printf("Palindrome valid");
        return true;
    }
    if(str[i] == str[n - 1]){
        check(str,  n - 1,  i + 1);
    }else{
        printf("Palindrome invalid");
         return false;
    }





}



int main(){
    char str[50];

    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';


   check(str, strlen(str), 0);



    return 0;
}