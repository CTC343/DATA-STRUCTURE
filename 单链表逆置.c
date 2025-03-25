#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

// 初始化链表
void InitList(LinkList* L) {
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
}

// 从头插法创建链表
void CreateFormHead(LinkList L) {
    Node* s;
    int c;
    while (1) {
        scanf("%d", &c);
        if (c != 0) {
            s = (Node*)malloc(sizeof(Node));
            s->data = c;
            s->next = L->next;
            L->next = s;
        } else {
            break;
        }
    }
}

// 输出链表
void PrintList(LinkList L) {
    Node* p = L->next; // 跳过头结点
    while (p != NULL) {
        printf("%d   ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 逆置链表
void ReverseList(LinkList L) {
    Node* prev = NULL;
    Node* current = L->next;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next; // 保存下一个节点
        current->next = prev; // 反转当前节点的指针
        prev = current;       // 移动 prev 和 current
        current = next;
    }
    L->next = prev; // 更新头结点的指针
}

int main() {
    LinkList L;
    InitList(&L); // 初始化链表
    //printf("Enter the elements of the list (end with 0):\n");
    CreateFormHead(L); // 创建链表
    
	ReverseList(L);// 逆置链表
	
    printf("The sequence before the reverse:");
    PrintList(L); // 输出逆置前的链表

    ReverseList(L);

    printf("Inverse sequence:");
    PrintList(L); // 输出逆置后的链表

    return 0;
}




