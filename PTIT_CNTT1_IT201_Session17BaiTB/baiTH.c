#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *code;
    char *name;
    int creditHours;
}Subject;

typedef struct Node {
    Subject sub;
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct {
    Node * front;
    Node * rear;
}Queue;

Node *createNode(const char code [], const char name[], const int creditHours ) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Failed to allocate memory !!|\n");
        return NULL;
    }
    newNode -> sub.name = (char *)malloc(strlen(name) * sizeof(char));
    newNode -> sub.code = (char *)malloc(strlen(code) * sizeof(char));

    newNode -> sub.creditHours = creditHours;
    strcpy(newNode -> sub.name, name);
    strcpy(newNode -> sub.code, code);

    newNode -> next = newNode -> prev = NULL;
    return newNode;
}


Queue *createQue() {
    Queue *newQue = (Queue *)malloc(sizeof(Queue));
    printf("Failed to allocate memory !!|\n");
    if (newQue == NULL) {
        return NULL;
    }
    newQue -> front =  newQue -> rear =  NULL;
    return newQue;
}

int isEmpty(Queue *q) {
    return q -> front == NULL;
}

void endQue(Queue *q, const char code [], const char name[], const int creditHours ) {
    Node *newNode =  createNode(code,name,creditHours);
    if (newNode == NULL) {
        return;
    }

    if (q -> front == NULL) {
        q -> front = q -> rear = newNode;
    }

    q -> rear -> next = newNode;
    q -> rear = newNode;
}




Subject delQue(Queue *q) {
    if (isEmpty(q)) {
        const Subject empty = {NULL, NULL, 0};
        printf("Queue is empty!!\n");
        return empty;
    }

    const Subject tempVal = q -> front -> sub;

    Node *temp = q -> front;
    q -> front  = q -> front -> next;
    free(temp);

    if ( q -> front == NULL) {
        q -> rear = NULL;
    }
    return tempVal;
}

// declare Function

//1. add Subject to list
Node *addSubject(Node *Subject);
//1.1 Check codeSubject
bool checkCodeDuplicate(char text[], const Node *head) {
    const Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp -> sub.code, text) == 0) {
            printf("Vui long Nhap lai !!\n");
            return false;
        }
        temp = temp -> next;
    }
    return true;
}
//2. print list
void printListSub( Node *subList);
//3. SearchSubject
Node* searchSubject( Node *subList, bool delete);
//4. Sort the list subject;
void SortTheListSub( Node *subList, int i);
//5. total credit Hours
void SumOfCreditHours(const Node *head);
void SumOfCreditHours(const Node *head);








//6. change subject status to completed
Node* addSubCompleted( Node** Subject, Node *SubjectDone);

//7. Undo Subject new add
void UndoSub();
//8. Manager the list of student waiting
void managerListStu();



// menu
void printfMenu() {
    printf(" ----- Menu -----\n");
    printf("1. Them mon hoc dang ki\n");
    printf("2. in cac mon hoc tron list\n");
    printf("3. Tìm kiếm môn học theo mã\n");
    printf("4. Sắp xếp danh sách môn học theo tên\n");
    printf("5. Tính tổng số tín chỉ đã đăng ký\n");
    printf("6. Chuyển một môn học sang danh sách “đã hoàn thành” \n");
    printf("7. Hoàn tác thao tác thêm môn gần nhất \n");
    printf("8. Quản lý danh sách sinh viên chờ được xử lý đăng ký môn học\n");
    printf("9. Thoát chương trình\n");
}




int main() {
    int menu;
    int menu1;
    // List Subject
    Node* nodeSubject = NULL;
    Node* NodeSubjectDone = NULL;

    do {
        printfMenu();
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n==== ADD SUBJECT ====\n");
                nodeSubject = addSubject(nodeSubject);
                break;
            case 2:
                printListSub(nodeSubject);
                break;
            case 3:
                searchSubject(nodeSubject, false);
                break;
            case 4:

                do {
                    printf("1. Xap xep tang dan: \n");
                    printf("2. Xap xep Giam dan: \n");
                    printf("3. Exit: \n");

                    scanf("%d", &menu1);
                }while (menu1 != 1 && menu1 != 2 && menu1 != 3);
                if (menu1 < 3) {
                    SortTheListSub(nodeSubject, menu1);
                }
                break;
            case 5:
                SumOfCreditHours(nodeSubject);
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                printf("Exit\n");
                break;
            default:
                printf("invalid\n");

        }

    }while (menu != 9);


}





// YÊU CẦU CHỨC NĂNG:
//     •	Thêm môn học vào danh sách đăng ký ( danh sách liên kết đơn)
//     •	Mỗi môn học gồm: mã môn (chuỗi), tên môn học (chuỗi), số tín chỉ (số nguyên).
//     •	Cho phép người dùng nhập nhiều môn học. Không cho phép trùng mã môn.
Node* addSubject(Node *Subject) {
    char name[100];
    char code[100];
    int creditHours;
    getchar();

    do {
        printf("\n Nhap Ma Mon Hoc :");
        fgets(code, sizeof(code), stdin);
        code[strcspn(code, "\n")] = '\0';
    }while ( checkCodeDuplicate(code, Subject ) != true);




    printf("\n Nhap Ten Mon Hoc :");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("\n Nhap So tin chi Mon Hoc :");
    scanf("%d", &creditHours);

    Node *temp = createNode(code, name, creditHours);

    if (temp == NULL) {
        return Subject;
    }
    temp -> next = Subject;
    return temp;

}


void printListSub(Node *subList) {
    Node *current = subList;
    if (current == NULL) {
        printf("\n===========KHONG CO MON HOC NAO=================\n");
        return;
    }
    int i = 1;
    printf("\n===============ALL SUBJECT==================\n");
    while (current != NULL) {
        printf("| %d. MA mon: %5s  |Ten Mon: %25s  |So tin chi:%5d    |\n",i, current -> sub.code, current -> sub.name, current -> sub.creditHours );
        current = current -> next;
    }
    printf("===============End==================\n");
}

//     •	Tìm kiếm môn học theo mã ( search )
//     •	Nhập mã môn cần tìm.
//     •	In ra thông tin môn học nếu tìm thấy, nếu không thì thông báo không tồn tại.
Node* searchSubject( Node *subList, const bool delete) {
    char text[100];
    printf("Nhap ma mon hoc: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    Node *current = subList;
    if (current == NULL) {
        printf("\n===========KHONG CO MON HOC NAO=================\n");
        return NULL;
    }

    int i = 1;
    while (current != NULL) {
        if (strcmp(current -> sub.code, text) == 0) {
            printf("| %d. MA mon: %5s  |Ten Mon: %25s  |So tin chi:%5d    |\n",i, current -> sub.code, current -> sub.name, current -> sub.creditHours );
            i++;
            return current;
        }
        current = current -> next;
    }
    if ( i == 1) {
        printf("\n===========KHONG CO MON HOC NAO=================\n");

    }

    return NULL;

}


//     •	Sắp xếp danh sách môn học theo tên (tăng dần) (sort )
//     •	In ra danh sách môn học sau khi sắp xếp.



void SortTheListSub(Node *subList, const int i) {
    char a ,b;

    int swapped;
    const Node *ptr1 = NULL;

    Node *current = subList;
    if (current == NULL) {
        return;
    }
    do {
        swapped = 0;
        Node *ptr = current;
        while (ptr -> next != ptr1) {


            if (i == 1) {
                  a = ptr ->sub.name[0];
                  b =  ptr -> next -> sub.name[0];
            }else {
                b = ptr ->sub.name[0];
                a =  ptr -> next -> sub.name[0];
            }

            if ( a > b ) {
                const Subject temp = ptr -> sub;
                ptr -> sub = ptr -> next -> sub;
                ptr -> next -> sub = temp;
                swapped = 1;
            }
            ptr = ptr -> next;
        }
        ptr1 = ptr -> next;
    }while (swapped);
    printListSub(current);
}



//     •	Tính tổng số tín chỉ đã đăng ký
//     •	In ra tổng số tín chỉ của tất cả các môn học hiện tại.'

void SumOfCreditHours(const Node *head) {
    const Node *current = head;
    if (current == NULL) {
        return;
    }
    int sum = 0;
    while (current != NULL) {

        sum += current -> sub.creditHours;
        current = current -> next;
    }
    printf("Tong so tin chi la: %d\n", sum);
}


//     •	Chuyển một môn học sang danh sách “đã hoàn thành”  ( danh sách liên kết đôi )
//     •	Nhập mã môn cần chuyển.
//     •	Nếu tìm thấy thì xóa khỏi danh sách đăng ký và thêm vào danh sách đã hoàn thành.


Node* addSubCompleted(Node** Subject, Node *SubjectDone) {
    if (Subject == NULL || *Subject == NULL) {
        printf("Khong co mon hoc nao.\n");
        return SubjectDone;
    }

    Node *tempSub = searchSubject(*Subject, true);  // truyền *Subject, không phải Subject**
    if (tempSub == NULL) {
        return SubjectDone;
    }

    Node *temp = createNode(tempSub->sub.code, tempSub->sub.name, tempSub->sub.creditHours);
    if (temp == NULL) {
        return SubjectDone;
    }

    // Thêm vào danh sách đã hoàn thành
    temp->next = SubjectDone;
    if (SubjectDone != NULL) {
        SubjectDone->prev = temp;
    }
    SubjectDone = temp;

    // Tìm và xóa node khỏi danh sách đăng ký
    Node **indirect = Subject;
    while (*indirect != NULL) {
        if (strcmp((*indirect)->sub.code, tempSub->sub.code) == 0 &&
            strcmp((*indirect)->sub.name, tempSub->sub.name) == 0 &&
            (*indirect)->sub.creditHours == tempSub->sub.creditHours)
        {
            Node *toDelete = *indirect;
            *indirect = (*indirect)->next;
            free(toDelete->sub.code);
            free(toDelete->sub.name);
            free(toDelete);
            break;
        }
        indirect = &(*indirect)->next;
    }

    printf("Chuyen mon hoc thanh cong.\n");
    return SubjectDone;
}


//     •	Có thể duyệt danh sách đã hoàn thành theo cả chiều xuôi và ngược.
//     •	Hoàn tác thao tác thêm môn gần nhất
//     •	Nếu người dùng thêm nhầm môn học, có thể hoàn tác thao tác gần nhất (xóa môn vừa thêm khỏi danh sách đăng ký).






//     •	Quản lý danh sách sinh viên chờ được xử lý đăng ký môn học
//     •	Cho phép thêm sinh viên mới vào hàng đợi chờ xử lý.
//     •	Phục vụ sinh viên đầu tiên trong hàng đợi.

//     •	Hiển thị danh sách sinh viên đang chờ.

//     •	Thoát chương trình 