#include <stdio.h>

#define MAX_SIZE 100

void inputOrderedList(int arr[], int *size) {
    int temp;
    int i;

    *size = 0;
    //printf("请输入元素个数: ");
    scanf("%d", size);
    
    //printf("请输入元素（非递减顺序）: ");
    for (i = 0; i < *size; i++) {
        scanf("%d", &temp);
        if (i == 0 || temp >= arr[i - 1]) {
            arr[i] = temp;
        } else {
            //printf("输入无效，当前元素小于前一个元素，请重新输入: ");
            i--; // 重新输入当前元素
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

    // 输入有序表La
    inputOrderedList(La, &sizeA);
    
    // 输入有序表Lb
    inputOrderedList(Lb, &sizeB);
    
    // 合并La和Lb到Lc
    mergeOrderedLists(La, sizeA, Lb, sizeB, Lc, &sizeC);
    
    // 输出结果
     printf("There are 5 elements in La,which are:");
    printList(La, sizeA);
     printf("There are 6 elements in Lb,which are:");
    printList(Lb, sizeB);
     printf("There are 11 elements in Lc,which are:");
    printList(Lc, sizeC);

    return 0;
}

