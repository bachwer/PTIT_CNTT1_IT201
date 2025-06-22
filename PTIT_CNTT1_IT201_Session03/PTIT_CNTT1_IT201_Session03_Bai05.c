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

    if( rows != cols){
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


    int sumMain = 0;
    int sumSecond = 0;
    for(int i = 0; i < cols;i++){
        for(int j = 0; j < rows; j++){
          if(i == j){
            sumMain += arr[i][j];
          }
          if(j == rows - 1 - i){
            sumSecond += arr[i][j];
          }
        }
    }

    printf("Main");
    printf("%d\n", sumMain);
    printf("Second");
    printf("%d", sumSecond);

    

    // 1 2 3
    // 4 5 6
    // 2 1 1





    





for (int i = 0; i < rows; i++) {
    free(arr[i]);
}
free(arr);

}

