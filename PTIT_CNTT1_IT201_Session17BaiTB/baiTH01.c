//
// Created by Macbook on 14/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
typedef struct{
    int credit;
    int id;
    char name[100];
}Subject;


typedef struct Node {
    Subject sub;
    struct Node * next;
    struct Node * prev;
}Node;


Node *createNode(const int credit,const int id, const char name[] ) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        return NULL;
    }
    temp -> sub.credit = credit;
    temp -> sub.id = id;
    strncpy(temp->sub.name, name, sizeof(temp->sub.name));
    temp->sub.name[sizeof(temp->sub.name) - 1] = '\0';
    temp -> next = NULL;
    temp -> prev = NULL;
    return temp;
}




// MENU CHỨC NĂNG:
// Thêm khóa học
bool checkCodeDuplicate(const int id,Node *subject) {
    if (subject == NULL) {
        return true;
    }

    Node *current = subject;

    while ( current != NULL) {
        if (current -> sub.id == id) {
            return false;
        }
        current = current -> next;
    }

    return true;
}

Node *addSubject(Node *subject) {
    int id, credit;
    char name[100];
    printf("----ADD SUBJECT----\n");
    do {
        printf("Nhap ID Subject (int): ");
        scanf("%d", &id);
    } while (id < 1 || checkCodeDuplicate(id, subject) != true);


    do {
        printf("Nhap credit Subject (int): ");
        scanf("%d", &credit);
    }while (credit < 1);

    getchar();
    printf("Nhap ten Subject : ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    Node *temp = createNode(credit, id, name);



    if (temp == NULL) {
        printf("Them khoa hoc that bai \n");
        return subject;
    }else {
        temp -> next = subject;
        if (subject != NULL) {
            subject -> prev = temp;
        }


        return temp;
    }
}
// Hiển thị danh sách khóa học

void showAllSub(Node *subject) {
    if (subject == NULL) {
        printf("Khong co khoa hoc nao\n");
        return;
    }

    const Node *current = subject;

    printf("|=================MON HOC=================|\n");
    int i = 1;
    while (current != NULL) {
        printf("| %d. ID Mon hoc: %5d | Ten mon: %25s | So tin chi: %5d | \n",
           i, current -> sub.id, current -> sub.name, current -> sub.credit);

        current = current -> next;
        i++;
    }
    printf("|=================END=================|\n");

}
// Xóa khóa học
Node *findSubjectByID(const int id, Node *head) {

    Node* current = head;
    while (current != NULL) {
        if (current -> sub.id == id) {

            return current;
        }
        current = current -> next;
    }

    printf("Khong tim thay");
    return NULL;
}

Node *delSubject(const int id,Node *subject) {
    if (subject == NULL) {
        printf("Ko co mon hoc \n");
        return subject;
    }


    Node *current = subject;
    if ( current -> sub.id == id) {
        Node* temp = current -> next;
        if (temp != NULL) {
            temp -> prev = NULL;
        }
        printf("DA xoa !\n");
        free(current);
        return temp;
    }

    const Node* toDelete = findSubjectByID(id, subject);
    if (toDelete == NULL) {
        printf("KO tim thay mon hoc: 1 \n");
        return subject;
    }
    if (toDelete->prev != NULL) {
        toDelete->prev->next = toDelete->next;
    }
    if (toDelete->next != NULL) {
        toDelete->next->prev = toDelete->prev;
    }

    return subject;
}

// Cập nhật thông tin khóa học

Node *UpdateInforSub(Node *subject) {
    int id;
    printf("Nhap Id mon hoc de sua : ");
    scanf("%d", &id);
    Node *temp = findSubjectByID(id, subject);

    if ( temp == NULL) {
        printf("KO tim thay mon hoc");
        return subject;
    }

    printf("Nhap ten moi: ");
    getchar();
    char newName[100];
    fgets(newName, sizeof(newName), stdin);
    newName[strcspn(newName, "\n")] = '\0';
    strncpy(temp->sub.name, newName, sizeof(temp->sub.name));

    temp->sub.name[sizeof(temp->sub.name) - 1] = '\0';

    printf("Nhap tin chi moi: ");
    scanf("%d", &temp->sub.credit);

    printf("Cap nhat thanh cong!\n");
    return subject;
}




// Đánh dấu khóa học đã hoàn thành
Node *changeNode(Node **Subject, Node *change) {
    int id;
    printf("Nhap id mon hoc can chuyen: ");
    scanf("%d", &id);
    Node *temp = findSubjectByID(id, *Subject);
    if (temp == NULL) {
        printf("Khong tm thay khoa hoc\n");
        return change;
    }

    Node *newNode = createNode(temp->sub.credit, temp->sub.id, temp->sub.name);    if (newNode == NULL) {
        return change;
    }
    *Subject = delSubject(id, *Subject);

    newNode -> next =  change;
    if (change != NULL) {
        change -> prev = newNode;
    }
    printf("Thanh cong\n");
    return newNode;
}

// Sắp xếp khóa học theo số tín chỉ
void sortByCredit(Node *subject) {
    if (subject == NULL) {
        return;
    }

    bool swaped;
    Node *last = NULL;

    do {
        swaped = false;
        Node *ptr = subject;
        while (ptr -> next != last) {
            if (ptr -> sub.credit > ptr -> next -> sub.credit) {
                Subject temp = ptr -> sub;
                ptr -> sub = ptr -> next -> sub;
                ptr -> next -> sub = temp;
                swaped = true;
            }
            ptr = ptr -> next;
        }
        last = ptr;
    }while (swaped);

    showAllSub(subject);
}







// Tìm kiếm khóa học theo tên

void SearchSubByName(const Node *subject) {
    char name[100];

    getchar();
    printf("Nhap ten can tim kiem: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    const Node *current = subject;

    printf("|=================MON HOC=================|\n");
    int i = 1;
    while (current != NULL) {
      if (strcmp(current -> sub.name, name) == 0) {
          printf("| %d. ID Mon hoc: %5d | Ten mon: %25s | So tin chi: %5d | \n",
         i, current -> sub.id, current -> sub.name, current -> sub.credit);
          i++;
      }
        current = current -> next;

    }
    printf("|=================END=================|\n");
    if (i == 1) {
        printf("Khong tim thay phan tu:!!\n");
    }
}








int main() {

    Node * Subject = NULL;
    Node *SubjectDone = NULL;
    int id;


    int choice;
    do {
        printf("----------MENU-----------\n");
        printf("1. Thêm khóa học\n");
        printf("2. Hiển thị danh sách khóa học\n");
        printf("3. Xóa khóa học\n");
        printf("4. Cập nhật thông tin khóa học\n");
        printf("5. Đánh dấu khóa học đã hoàn thành\n");
        printf("6. Sắp xếp khóa học theo số tín chỉ\n");
        printf("7. Tìm kiếm khóa học theo tên\n");
        printf("8. Thoat\n");
        scanf("%d", &choice);



        switch (choice) {
            case 1:
                Subject = addSubject(Subject);
                break;
            case 2:
                showAllSub(Subject);
                break;
            case 3:
                do {
                    printf("Nhap id Subject de xoa: ");
                    scanf("%d", &id);
                }while (id < 1);
                Subject = delSubject(id,Subject);
                break;
            case 4:


                Subject = UpdateInforSub(Subject);
                break;
            case 5:
                SubjectDone = changeNode(&Subject, SubjectDone);
                showAllSub(SubjectDone);
                break;
            case 6:
                sortByCredit(Subject);
                break;
            case 7:
                SearchSubByName(Subject);
                break;
            case 8:
                free(Subject);
                free(SubjectDone);
                break;
            default: ;
                showAllSub(SubjectDone);
                break;
        }
    }while (choice != 8);
}









void sortList(Node *head) {
    if (!head) return;
    int swapped;
    do {
        swapped = 0;
        Node *ptr = head;
        while (ptr->next) {
            if (ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
    } while (swapped);
}



