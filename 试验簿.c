#include <stdio.h>

#define MAX_SIZE 100

void inputOrderedList(int arr[], int *size) {
    int temp;
    int i;

    *size = 0;
    //printf("������Ԫ�ظ���: ");
    scanf("%d", size);
    
    //printf("������Ԫ�أ��ǵݼ�˳��: ");
    for (i = 0; i < *size; i++) {
        scanf("%d", &temp);
        if (i == 0 || temp >= arr[i - 1]) {
            arr[i] = temp;
        } else {
            //printf("������Ч����ǰԪ��С��ǰһ��Ԫ�أ�����������: ");
            i--; // �������뵱ǰԪ��
        }
    }
}

void mergeOrderedLists(int La[], int sizeA, int Lb[], int sizeB, int Lc[], int *sizeC) {
    int i, j, k;

    i = 0;
    j = 0;
    k = 0;
    while (i < sizeA && j < sizeB) {
        if (La[i] <= Lb[j]) {
            Lc[k++] = La[i++];
        } else {
            Lc[k++] = Lb[j++];
        }
    }
    while (i < sizeA) {
        Lc[k++] = La[i++];
    }
    while (j < sizeB) {
        Lc[k++] = Lb[j++];
    }
    *sizeC = k;
}

void printList(int arr[], int size) {
    int i;

   
    for (i = 0; i < size; i++) {
        printf("%-4d", arr[i]);
    }
    printf("\n");
}

int main() {
    int La[MAX_SIZE], Lb[MAX_SIZE], Lc[MAX_SIZE];
    int sizeA, sizeB, sizeC;

    // ���������La
    inputOrderedList(La, &sizeA);
    
    // ���������Lb
    inputOrderedList(Lb, &sizeB);
    
    // �ϲ�La��Lb��Lc
    mergeOrderedLists(La, sizeA, Lb, sizeB, Lc, &sizeC);
    
    // ������
     printf("There are 5 elements in La,which are:");
    printList(La, sizeA);
     printf("There are 6 elements in Lb,which are:");
    printList(Lb, sizeB);
     printf("There are 11 elements in Lc,which are:");
    printList(Lc, sizeC);

    return 0;
}

