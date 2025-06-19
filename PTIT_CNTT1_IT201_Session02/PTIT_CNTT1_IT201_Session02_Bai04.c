#include <stdio.h>
#include <stdlib.h>





int main(){

    int n;
    scanf("%d ", &n);


    int *arr = (int *)malloc(n *sizeof(int));


    for(int i = 0; i < n; i++){

        scanf("%d", &arr[i]);
    }

    int pos; 
    printf("Nhap vi tri muon sua");
    scanf("%d", &pos);
    pos--;
    
    scanf("%d", &arr[pos]);

    printf("Nhap gia tri");
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }


    


}