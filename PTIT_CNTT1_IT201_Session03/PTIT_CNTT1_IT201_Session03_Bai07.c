#include <stdio.h>
#include <stdlib.h>



int main(){

    int rows = 0, cols = 0;
    scanf("%d", &cols);
    scanf("%d", &rows);

    if( rows < 1 || cols < 1){
        printf("invalid");
        return 0;
    }


    int **arr = (int **)malloc(rows * sizeof(int *));

    
    for(int i = 0; i < rows; i++){
        arr[i] = (int*)malloc(cols * sizeof(int));
    }


   
    for(int i = 0; i < cols;i++){
        for(int j = 0; j < rows; j++){
           scanf("%d", &arr[i][j]);
        }
    }

    printf("Nhap so hang :");
    int k;
    scanf("%d", &k);

    if(k > cols || k < 0){
        printf("invalid");
        return 0;
    }


    int sum = 0;
 
    for(int i = 0; i < cols;i++){
        for(int j = 0; j < rows; j++){
          if(k - 1 == i){
            sum += arr[i][j];
          }
        }
    }


    printf("\n%d", sum);
    





for (int i = 0; i < rows; i++) {
    free(arr[i]);
}
free(arr);

}

