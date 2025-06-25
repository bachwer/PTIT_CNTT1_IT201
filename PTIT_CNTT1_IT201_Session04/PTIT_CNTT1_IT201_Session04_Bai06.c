#include <stdio.h>
#include <stdlib.h>


struct students {
    int id;
    char name[100] ;
    int age;
    
};

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


    int id;
    printf("nhap id: ");
    scanf("%d", &id);

    for(int i = 0; i < 5; i++){
        if(sv[i].id == id){
            printf("ID: %d \n", sv[i].id);
            printf("Name: %s \n", sv[i].name);
            printf("Age: %d \n", sv[i].age);
        }
    }

    








}