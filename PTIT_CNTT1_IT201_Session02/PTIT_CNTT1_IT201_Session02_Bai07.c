#include <stdio.h>
#include <stdlib.h>


int main(){


    int n;
    scanf("%d", &n);
    int *num = (int *) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }


    int target;
    scanf("%d", &target);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (num[i] + num[j] == target){
                printf("%d %d", num[i], num[j]);
                return 1;
            }
        }
    }

    printf("khong tim thay");
}