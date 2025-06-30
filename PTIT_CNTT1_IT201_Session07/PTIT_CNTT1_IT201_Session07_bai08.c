#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


void SortCols(int ** arr, int cols, int row, int w);












void printArr(int **arr, int cols, int rows) {

   for (int i = 0; i < cols; i++) {
      for (int j = 0; j < rows; j++) {
         printf("%d " , arr[i][j]);
      }
      printf("\n");
   }
}


void SortCols(int **arr, int cols, int rows, int row) {
   for (int i = 0; i < cols - 1; i++) {
      for (int j = 0; j < cols - i - 1; j++) {
         if (arr[j][row] > arr[j + 1][row]) {
            const int temp = arr[j][row];
            arr[j][row] = arr[j + 1][row];
            arr[j + 1][row] = temp;
         }
      }
   }

   printArr(arr, cols, rows);
}




int main(){

   int cols;
   int rows;

   scanf("%d", &cols);
   scanf("%d", &rows);


   int **arr = (int **)malloc(cols * sizeof(int *));

   for (int i = 0; i < cols; i++) {
      arr[i] = (int *)malloc(rows *sizeof(int));
   }







   for (int i = 0; i < cols; i++) {
      for (int j = 0; j < rows; j++) {
         scanf("%d" , &arr[i][j]);
      }
   }


   int rowsSort1;
   printf("Cols: ");
   scanf("%d", &rowsSort1);
   rowsSort1--;


   SortCols(arr, cols, rows, rowsSort1);




   for (int i = 0; i < cols; i++) {
      free(arr[i]);
   }
   free(arr);


   return 0;
}
