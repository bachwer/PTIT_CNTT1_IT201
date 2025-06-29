    #include <stdio.h>


    void intTBinnary(int n){

        if ( n == 0) {
            return;
        }
        printf("%d", n % 2);
        intTBinnary(n/2);

    }



    int main(){
        int n;
        scanf("%d", &n);
        intTBinnary(n);

    }