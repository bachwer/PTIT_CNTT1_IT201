#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


struct students {
    int id;
    char name[100] ;
    int age;
    
};

void toLowerCase(char str[]);

void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}


int main(){
    
    struct students sv[5];

    for(int i = 0; i < 5; i++){
        printf("----SV %d ------\n", i + 1);
        printf("Nhap ID: ");
        scanf("%d", &sv[i].id);
        printf("\n Nhap Name: ");
        getchar();
        fgets(sv[i].name, sizeof(sv[i].name), stdin);
        sv[i].name[strcspn(sv[i].name, "\n")] = 0;

        printf("\nNhap Age: ");
        scanf("%d", &sv[i].age);
    }

    char name[50];
    printf("nhap ten: ");
    getchar();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
   
    for(int i = 0; i < 5; i++){
        char namecy[50];
        strcpy(namecy, sv[i].name);
        toLowerCase(namecy);
        toLowerCase(name);

        
        if(strstr(name, namecy)!= NULL){
            printf("ID: %d \n", sv[i].id);
            printf("Name: %s \n", sv[i].name);
            printf("Age: %d \n", sv[i].age);
        }
    }

    







}