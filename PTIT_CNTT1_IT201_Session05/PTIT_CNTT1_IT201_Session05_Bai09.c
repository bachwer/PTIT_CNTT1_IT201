#include <stdio.h>
#include <stdlib.h>

int step(int row, int col){

    if(row == 1 || col == 1){
        return 1;
    }

    return step(row - 1, col) + step(row, col - 1);

}



int main(){

    int rows;
    int cols;

    scanf("%d", &cols);
    scanf("%d", &rows);

    int res;

    res = step(rows, cols);

    printf("%d", res);



  






    return 0;
}