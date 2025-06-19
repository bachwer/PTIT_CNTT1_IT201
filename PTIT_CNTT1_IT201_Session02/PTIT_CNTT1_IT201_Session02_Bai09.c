#include <stdio.h>
#include <stdlib.h>


int main(){


    int n;
    scanf("%d", &n);
    int *num = (int *) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }

    int check = 0;
    for(int i = 0; i < n; i ++){
        if(check < num[i]){
            check = num[i];
      
        }
}

    printf("%d %d", check);

}