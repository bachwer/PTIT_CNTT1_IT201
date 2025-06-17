#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool check(char string1[], char string2[]){
    int str1 = strlen(string1);

    int str2 = strlen(string2);

    if(str1 != str2){
        return false;
    }


    //time complexity O(n)
    for(int i = 0; i < str1 / 2; i++){
        if(string1[i] != string2[str1 - i - 1]){
          return false;
        }
    }

    return true;


}


int main(){
    char str1[100];
    char str2[100];
    scanf("%s[^\n]", str1);
    getchar();
    scanf("%s[^\n]", str2);
    getchar();


    bool True = check(str1, str2);

    if(True){
        printf("True");
    }else{
        printf("Flase");
    }


}