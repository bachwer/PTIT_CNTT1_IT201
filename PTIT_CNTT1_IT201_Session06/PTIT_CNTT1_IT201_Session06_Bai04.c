#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


void thapHaNoi(int n, char cotNguon, char cotTrungGian, char cotDich) {
   if (n == 1) {
      printf("Đĩa 1 di chuyển từ %c sang %c\n", cotNguon, cotDich);
      return;
   }

   thapHaNoi(n - 1, cotNguon, cotDich, cotTrungGian);


   printf("Đĩa %d di chuyển từ %c sang %c\n", n, cotNguon, cotDich);

   thapHaNoi(n - 1, cotTrungGian, cotNguon, cotDich);
}










}



int main(){
   int n;
   scanf("%d",&n);




   thapHaNoi(n,'a','b','c');



   return 0;
}







