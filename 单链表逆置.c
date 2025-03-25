#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

// ��ʼ������
void InitList(LinkList* L) {
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
}

// ��ͷ�巨��������
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

// �������
void PrintList(LinkList L) {
    Node* p = L->next; // ����ͷ���
    while (p != NULL) {
        printf("%d   ", p->data);
        p = p->next;
    }
    printf("\n");
}

// ��������
void ReverseList(LinkList L) {
    Node* prev = NULL;
    Node* current = L->next;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next; // ������һ���ڵ�
        current->next = prev; // ��ת��ǰ�ڵ��ָ��
        prev = current;       // �ƶ� prev �� current
        current = next;
    }
    L->next = prev; // ����ͷ����ָ��
}

int main() {
    LinkList L;
    InitList(&L); // ��ʼ������
    //printf("Enter the elements of the list (end with 0):\n");
    CreateFormHead(L); // ��������
    
	ReverseList(L);// ��������
	
    printf("The sequence before the reverse:");
    PrintList(L); // �������ǰ������

    ReverseList(L);

    printf("Inverse sequence:");
    PrintList(L); // ������ú������

    return 0;
}




