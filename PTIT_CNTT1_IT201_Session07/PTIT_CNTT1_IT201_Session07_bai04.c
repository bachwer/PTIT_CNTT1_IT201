#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


void printSting(char arr[], const int n) {

   for (int i = 0; i < n; i++) {
      if (arr[i] == ' ') {
         continue;
      }
      printf("%c", arr[i]);
   }


}


void sortChar(char arr[], const int n) {

   for (int i = 0; i < n - 1; i ++) {
      for (int j = 0; j < n -i - 1; j++) {
         if (arr[j] > arr[j + 1]){
            const char temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1]= temp;
         }
      }
   }

   printSting(arr, n);

}

int main(){

   int str[100];

   fgets(str, sizeof(str), stdin);
   str[strlen(str) - 1] = '\0';
   const int n = strlen(str);
   sortChar(str, n);

   free(arr);


   return 0;
}
