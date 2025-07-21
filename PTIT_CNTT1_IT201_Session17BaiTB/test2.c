//
// Created by Macbook on 15/07/2025.
//

// (Technical Support Request Manager)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef enum { LOW, MEDIUM, HIGH, EMPTY } Priority;


typedef struct {
    char *name;
    char *content;
    Priority level;
    char *time;
}SupportRequest;

typedef struct Node {
    SupportRequest request;
    struct Node *next;
}Node;

typedef struct {
    Node *top;
}Stack;
typedef struct {
    Node *front;
    Node *rear;
}Queue;



// •	Tên người dùng
// •	Nội dung yêu cầu
// •	Mức độ ưu tiên (High / Medium / Low)
// •	Thời gian gửi yêu cầu

Node *createNode(const char* name, const char *contents,const Priority level, const char *time ) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error\n");
        return NULL;
    }
    newNode -> request.name = (char *)malloc(strlen(name)*sizeof(char));
    newNode -> request.content = (char *)malloc(strlen(contents)*sizeof(char));
    newNode -> request.time = (char *)malloc(strlen(time)*sizeof(char));
    strcpy( newNode -> request.name, name);
    strcpy( newNode -> request.content, contents);
    strcpy( newNode -> request.time, time);
    newNode -> request.level = level;
    newNode -> next = NULL;
    return newNode;
}

//stack;

Stack *newStack() {
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    if (newStack == NULL) {
        printf("Error\n");
        return NULL;
    }
    newStack -> top= NULL;
    return newStack;
}


void push(Stack *stack, const char *name, const char *contents, const Priority level, const char *time) {
    Node *newNode = createNode(name, contents, level, time );
    if (newNode == NULL) {
        return;
    }
    newNode -> next = stack -> top;
    stack -> top = newNode;
}


SupportRequest pop(Stack *stack) {
    if (stack -> top == NULL) {
        SupportRequest infoRequest;
        infoRequest.name = (char *)malloc(strlen("NULL")*sizeof(char));
        infoRequest.content = (char *)malloc(strlen("NULL")*sizeof(char));
        infoRequest.time = (char *)malloc(strlen("NULL")*sizeof(char));

        strcpy(infoRequest.name, "NULL");
        strcpy( infoRequest.content, "NULL");
        strcpy( infoRequest.time, "NULL");
        infoRequest.level =  EMPTY;
        return infoRequest;
    }

    Node *temp = stack -> top;

    SupportRequest infoRequest;
    infoRequest.name = strdup(temp -> request.name);
    infoRequest.content = strdup(temp -> request.content);
    infoRequest.time = strdup(temp -> request.time);
    infoRequest.level =  temp -> request.level;

    stack -> top = temp -> next;

    free(temp -> request.name);
    free(temp -> request.content);
    free(temp -> request.time);
    free(temp);

    return infoRequest;

}


SupportRequest peekStack(const Stack *stack) {
    if (stack -> top == NULL) {
        SupportRequest infoRequest;
        infoRequest.name = (char *)malloc(strlen("NULL")*sizeof(char));
        infoRequest.content = (char *)malloc(strlen("NULL")*sizeof(char));
        infoRequest.time = (char *)malloc(strlen("NULL")*sizeof(char));

        strcpy(infoRequest.name, "NULL");
        strcpy( infoRequest.content, "NULL");
        strcpy( infoRequest.time, "NULL");
        infoRequest.level =  EMPTY;
        return infoRequest;
    }

    Node *temp = stack -> top;
    SupportRequest infoRequest;
    infoRequest.name = strdup(temp -> request.name);
    infoRequest.content = strdup(temp -> request.content);
    infoRequest.time = strdup(temp -> request.time);
    infoRequest.level =  temp -> request.level;
    return infoRequest;

}

// queue
Queue *createQue() {
    Queue *newQue = (Queue *)malloc(sizeof(Queue));
    if (newQue == NULL) {
        printf("Error\n");
        return NULL;
    }
    newQue -> front = newQue -> rear = NULL;
    return newQue;
}


void endQue(Queue *Que, const char *name, const char *contents, const Priority level, const char *time) {
    Node *newNode = createNode(name, contents, level, time );

    if (Que -> front == NULL) {
        Que -> front = Que -> rear = newNode;
        return;

    }

    Que -> rear -> next = newNode;
    Que -> rear = newNode;
}

//fix function return struct ->>


SupportRequest delQue(Queue *Que) {
    if (Que -> front == NULL) {
        SupportRequest infoRequest;
        infoRequest.name = (char *)malloc(strlen("NULL")*sizeof(char));
        infoRequest.content = (char *)malloc(strlen("NULL")*sizeof(char));
        infoRequest.time = (char *)malloc(strlen("NULL")*sizeof(char));

        strcpy(infoRequest.name, "NULL");
        strcpy( infoRequest.content, "NULL");
        strcpy( infoRequest.time, "NULL");
        infoRequest.level =  EMPTY;
        return infoRequest;
    }
    Node *temp = Que -> front;
    SupportRequest infoRequest;
    infoRequest.name = strdup(temp -> request.name);
    infoRequest.content = strdup(temp -> request.content);
    infoRequest.time = strdup(temp -> request.time);
    infoRequest.level =  temp -> request.level;


    Que -> front =Que -> front -> next;
    if (Que -> front == NULL) {
        Que -> rear = NULL;
    }

    free(temp -> request.name);
    free(temp -> request.content);
    free(temp -> request.time);
    free(temp);
    return infoRequest;
}


SupportRequest peek(const Queue *Que) {
    if (Que -> front == NULL) {
        SupportRequest infoRequest;
        infoRequest.name = (char *)malloc(strlen("NULL")*sizeof(char));
        infoRequest.content = (char *)malloc(strlen("NULL")*sizeof(char));
        infoRequest.time = (char *)malloc(strlen("NULL")*sizeof(char));

        strcpy(infoRequest.name, "NULL");
        strcpy( infoRequest.content, "NULL");
        strcpy( infoRequest.time, "NULL");
        infoRequest.level =  EMPTY;
        return infoRequest;
    }
    const Node *temp = Que -> front;
    SupportRequest infoRequest;
    infoRequest.name = strdup(temp -> request.name);
    infoRequest.content = strdup(temp -> request.content);
    infoRequest.time = strdup(temp -> request.time);
    infoRequest.level =  temp -> request.level;

    return infoRequest;
}




// time
char* getTime() {
    static char buffer[10];
    const time_t now = time(NULL);
    const struct tm *t = localtime(&now);

    strftime(buffer, sizeof(buffer), "%H:%M:%S", t);
    return buffer;
}



// A. Gửi yêu cầu mới (CALL)
void createRequest(Queue *requestAll, Queue *requestHigh, Queue *requestMedium, Queue *requestLow);


// B. Xử lý yêu cầu (PROCESS)
void ProcessRequest(Queue **requestAll, Queue *requestHigh, Queue *requestMedium, Queue *requestLow,  Stack *requested);

// C. Xem lại yêu cầu đã xử lý gần nhất (LAST)
void showRequestNew(const Stack *requested);
// D. Hiển thị tất cả yêu cầu chờ (SHOW_QUEUE)

void showARequestFirst(const Queue *requestAll);

// E. Hiển thị tất cả yêu cầu đã xử lý (SHOW_STACK)
void showAllRequest(const Stack *requested);

// F. Thoát chương trình (EXIT)
void freeQue(Queue *q);
void freeStack(Stack *s);


int main() {
    int choice;
    Queue *requestAll = createQue();

    //requestLeve;
    Queue *requestHigh =  createQue();
    Queue *requestMedium = createQue();
    Queue *requestLow = createQue();
    //requested
    Stack *requested = newStack();



    do {
        printf("----------------MENu----------------\n");
        printf("1.Gửi yêu cầu mới (CALL)\n");
        printf("2.Xử lý yêu cầu (PROCESS)\n");
        printf("3.Xem lại yêu cầu đã xử lý gần nhất (LAST)\n");
        printf("4.Hiển thị tất cả yêu cầu chờ (SHOW_QUEUE)\n");
        printf("5.Hiển thị tất cả yêu cầu đã xử lý (SHOW_STACK) \n");
        printf("6.Thoát chương trình (EXIT) \n");
        printf("Chon Y/c: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                createRequest(requestAll, requestHigh, requestMedium, requestLow);
                break;
            case 2:
                ProcessRequest(&requestAll, requestHigh, requestMedium, requestLow, requested);
                break;
            case 3:
                showRequestNew(requested);
                break;
            case 4:
                showARequestFirst(requestAll);
                break;
            case 5:
                showAllRequest(requested);
                break;
            case 6:
                freeQue(requestAll);
                freeQue(requestHigh);
                freeQue(requestMedium);
                freeQue(requestLow);
                freeStack(requested);
                printf("Exited\n");
                break;
            default:;
                break;
        }


    }while (choice != 6);

}










// Đề Bài: Trình Quản Lý Yêu Cầu Hỗ Trợ Kỹ Thuật (Technical Support Request Manager)
//
// Mô tả tổng quan:
//
// Bạn được yêu cầu xây dựng một chương trình để quản lý các yêu cầu hỗ trợ kỹ thuật từ người dùng. Mỗi yêu cầu bao gồm thông tin người gửi, nội dung yêu cầu, mức độ ưu tiên và thời gian gửi. Chương trình phải hỗ trợ các chức năng sau:
//
// ⸻
//
// 1. Cấu trúc dữ liệu cần sử dụng:
// 	•	Struct SupportRequest chứa:
// 	•	name: Tên người dùng (chuỗi ký tự).
// 	•	content: Nội dung yêu cầu hỗ trợ (chuỗi ký tự).
// 	•	level: Mức độ ưu tiên (Kiểu liệt kê Priority gồm các mức: LOW, MEDIUM, HIGH).
// 	•	time: Thời gian gửi yêu cầu (chuỗi giờ dưới định dạng HH:MM:SS).
// 	•	Struct Node là nút danh sách liên kết đơn chứa:
// 	•	SupportRequest request'
// 	•	Con trỏ đến nút tiếp theo.

// 	•	Stack (Ngăn xếp) để quản lý các yêu cầu hỗ trợ đã được xử lý gần đây nhất.
// 	•	Queue (Hàng đợi) để quản lý các yêu cầu chờ xử lý theo thứ tự FIFO (First In First Out).

//
// ⸻
//
// 2. Chức năng yêu cầu:

// A. Gửi yêu cầu mới (CALL)
// 	•	Nhập từ người dùng:
// 	•	Tên người dùng.
// 	•	Nội dung yêu cầu.
// 	•	Mức độ ưu tiên (High / Medium / Low).
// 	•	Lấy thời gian gửi hiện tại (sử dụng time.h).
// 	•	Thêm yêu cầu vào Queue chờ xử lý.
void createRequest(Queue *requestAll, Queue *requestHigh, Queue *requestMedium, Queue *requestLow){
    int menu;
    char name[50];
    char content[50];
    Priority level;
    printf("------Enter information------\n");
    getchar();
    printf("Enter name user: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    printf("Enter content request: ");
    fgets(content, sizeof(content), stdin);
    content[strlen(content) - 1] = '\0';
    do {
        printf("---Priority level--- \n1.High \n2.Medium  \n3.Low\n");
        scanf("%d", &menu);
    }while (menu < 1 || menu > 3);

    if (menu == 1) {
        level = HIGH;
        endQue(requestHigh, name, content,level, getTime());
    }else if (menu == 2) {
        level = MEDIUM;
        endQue(requestMedium, name, content,level, getTime());
    }else {
        level = LOW;
        endQue(requestLow, name, content,level, getTime());
    }

    endQue(requestAll, name, content,level, getTime());
    printf("Save information success !!\n");
}
// B. Xử lý yêu cầu (PROCESS)
// 	•	Lấy yêu cầu đầu tiên từ Queue (nếu có).
// 	•	Đưa yêu cầu này vào Stack (lưu lịch sử yêu cầu đã xử lý).
// 	•	Hiển thị thông tin yêu cầu đã xử lý.
void ProcessRequest(Queue **requestAll, Queue *requestHigh, Queue *requestMedium, Queue *requestLow,  Stack *requested) {

    int i = 0;
    while (requestHigh -> front != NULL) {
        const SupportRequest infoRequest = delQue(requestHigh);
        if (infoRequest.level != EMPTY) {
            push(requested, infoRequest.name, infoRequest.content,  infoRequest.level, infoRequest.time  );
            i++;
        }
        printf(".");
    }


    while (requestMedium -> front != NULL) {
        const SupportRequest infoRequest = delQue(requestMedium);
        if (infoRequest.level != EMPTY) {
            push(requested, infoRequest.name, infoRequest.content,  infoRequest.level, infoRequest.time  );
            i++;
        }
        printf("..");
    }

    while (requestLow -> front != NULL) {
        const SupportRequest infoRequest = delQue(requestLow);
        if (infoRequest.level != EMPTY) {
            push(requested, infoRequest.name, infoRequest.content,  infoRequest.level, infoRequest.time  );
            i++;
        }
        printf("..\n");
    }

    printf("Da xu ly %d request\n", i);
    *requestAll = createQue();
}


// C. Xem lại yêu cầu đã xử lý gần nhất (LAST)
// 	•	Xem phần tử đầu của Stack (không xóa).
// 	•	Nếu Stack rỗng → thông báo.
void showRequestNew(const Stack *requested) {
    if (requested == NULL) {
        printf("Empty list\n");
        return;
    }
    const SupportRequest Request  = peekStack(requested);
    if (Request.level == EMPTY) {
        printf("Empty list\n");
        return;
    }
    const char *priorityStr[] = {"High", "Medium", "LOW"};
    printf("----------REQUEST--------\n");
    printf("- Name: %s \n",Request.name);
    printf("- Content: %s \n",Request.content);
    printf("- pro: %s \n",Request.name);
    printf("- Priority: %s\n", priorityStr[Request.level]);
    printf("- time: %s\n",Request.time);
    printf("------------END----------\n");
}




// D. Hiển thị tất cả yêu cầu chờ (SHOW_QUEUE)
// 	•	Duyệt và in toàn bộ Queue.
void showARequestFirst(const Queue *requestAll) {
    const Node *current = requestAll -> front;
    int i = 1;
    while (current != NULL) {
        const char *priorityStr[] = {"High", "Medium", "LOW"};
        const SupportRequest Request  = current -> request;
        if (Request.level == EMPTY) {
            printf("Empty list\n");
        }
        printf("----------REQUEST %d--------\n", i++);
        printf("- Name: %s \n",Request.name);
        printf("- Content: %s \n",Request.content);
        printf("- Priority: %s\n", priorityStr[Request.level]);
        printf("- time: %s\n",Request.time);
        printf("------------END----------\n");
        current = current -> next;
    }
    if (i == 1) {
        printf("Empty List\n");
    }
}




// E. Hiển thị tất cả yêu cầu đã xử lý (SHOW_STACK)
// 	•	Duyệt và in toàn bộ Stack.
void showAllRequest(const Stack *requested) {
    const Node *current = requested -> top;
    int i = 1;
    while (current != NULL) {
        const char *priorityStr[] = {"High", "Medium", "LOW"};
        const SupportRequest Request  = current -> request;
        if (Request.level == EMPTY) {
            printf("Empty list\n");
        }
        printf("----------REQUEST %d--------\n", i++);
        printf("- Name: %s \n",Request.name);
        printf("- Content: %s \n",Request.content);
        printf("- Priority: %s\n", priorityStr[Request.level]);
        printf("- time: %s\n",Request.time);
        printf("------------END----------\n");
        current = current -> next;
    }
    if (i == 1) {
        printf("Empty List !!\n");
    }
}




// F. Thoát chương trình (EXIT)
// 	•	Giải phóng toàn bộ bộ nhớ đã cấp phát.
void freeQue(Queue *q) {
    while (q -> front != NULL) {
        delQue(q);
    }
    free(q);

}
void freeStack(Stack *s) {
    if ( s  -> top!= NULL) {
        pop(s);
    }
    free(s);
}






// 4. Gợi ý mở rộng (tùy chọn nâng cao):
// 	•	Ưu tiên xử lý các yêu cầu HIGH trước nếu có.
// 	•	Lọc và thống kê số lượng yêu cầu theo mức độ ưu tiên.













