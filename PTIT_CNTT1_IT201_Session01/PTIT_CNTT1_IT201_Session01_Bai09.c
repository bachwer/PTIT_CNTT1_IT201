#include <stdio.h>
#include <stdlib.h>

//Time complexity: O(n * n)
//Space complexity: O(n * n)
void showMatrix(int **arr){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%d ", arr[i][j]);
        }
            printf("\n");
    }

}
//Time complexity: O(n * n)
//Space complexity: O(n * n)
void Maindiagonal(int **arr){
       for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){

                if(i == j){
                    printf("%d ", arr[i][j]);
                } else{
                    printf(" ");
                }

                }
                printf("\n");
               
            }
            
    }








int main(){
    int n = 5;

    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < 5; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = 1; matrix[0][3] = 0; matrix[0][4] = 0;
    matrix[1][0] = 0; matrix[1][1] = 1; matrix[1][2] = 0; matrix[1][3] = 0; matrix[1][4] = 0;
    matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1; matrix[2][3] = 0; matrix[2][4] = 0;
    matrix[3][0] = 0; matrix[3][1] = 1; matrix[3][2] = 0; matrix[3][3] = 1; matrix[3][4] = 0;
    matrix[4][0] = 0; matrix[4][1] = 1; matrix[4][2] = 0; matrix[4][3] = 1; matrix[4][4] = 1;

    showMatrix(matrix);
    Maindiagonal(matrix);




}