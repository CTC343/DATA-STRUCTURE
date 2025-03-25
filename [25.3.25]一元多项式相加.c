#include<stdio.h>
#include<stdlib.h>

typedef struct Polynode
{
	int coef;
	int exp;
	struct Polynode* next;
} Polynode, * Polylist;

Polylist PolyCreate()
{
	Polynode* head, * rear, * s;
	int c, e, last_exp = -1; // 初始化 last_exp 为无效值
	head = (Polynode*)malloc(sizeof(Polynode));
	rear = head;

	scanf("%d,%d", &c, &e);
	while (c != 0)
	{
		// 检查新输入的指数是否小于或等于上一个指数
		while (e <= last_exp)
		{
			scanf("%d", &e); // 只重新输入指数
		}

		s = (Polynode*)malloc(sizeof(Polynode));
		s->coef = c;
		s->exp = e;
		rear->next = s;
		rear = s;

		last_exp = e; // 更新 last_exp 为当前项的指数
		scanf("%d,%d", &c, &e);
	}
	rear->next = NULL; // 设置最后一项的下一个指针为 NULL
	return (head); // 返回多项式链表的头指针
}




void PolyAdd(Polylist polya, Polylist polyb)
{
	Polynode* p, * q, * tail, * temp;
	int sum;
	p = polya->next;
	q = polyb->next;
	tail = polya;
	while (p != NULL && q != NULL)
	{
		if (p->exp < q->exp)
		{
			tail->next = p;
			tail = p;
			p = p->next;
		}
		else if (p->exp == q->exp)
		{
			sum = p->coef + q->coef;
			if (sum != 0)
			{
				p->coef = sum;
				tail->next = p;
				tail = p;
				p = p->next;
				temp = q;
				q = q->next;
				free(temp);
			}
			else
			{
				temp = p;
				p = p->next;
				free(temp);
				temp = q;
				q = q->next;
				free(temp);
			}
		}
		else
		{
			tail->next = q;
			tail = q;
			q = q->next;
		}
	}
	if (p != NULL)
		tail->next = p;
	else
		tail->next = q;
	free(polyb);
}

int main()
{
	Polylist pa = PolyCreate(); // 输入pa
	printf("please input pa,end with 0:\n");
	printf("pa:");

	// 输出pa式子
	Polynode* current = pa->next; // 从头节点的下一个开始
	while (current != NULL) {
		if (current->coef > 0 && current != pa->next) {
			printf("+"); // 如果系数为正且不是第一个项，输出加号
		}
		if (current->exp == 0) {
			printf("%d", current->coef); // 指数为0时只输出系数
		}
		else if (current->exp == 1) {
			if (current->coef == 1)
			{
				printf("x");
			}
			else
				printf("%dx", current->coef); // 指数为1时只输出系数和x
		}
		else {
			printf("%dx^%d", current->coef, current->exp); // 其他情况正常输出
		}
		current = current->next;
	}
	printf("\n");

	Polylist pb = PolyCreate(); // 输入pb
	printf("please input pb,end with 0:\n");
	printf("pb:");

	// 输出pb式子
	current = pb->next; // 从头节点的下一个开始
	while (current != NULL) {
		if (current->coef > 0 && current != pb->next) {
			printf("+"); // 如果系数为正且不是第一个项，输出加号
		}
		if (current->exp == 0) {
			printf("%d", current->coef); // 指数为0时只输出系数
		}
		else if (current->exp == 1) {
			if (current->coef == 1)
			{
				printf("x");
			}
			else
				printf("%dx", current->coef); // 指数为1时只输出系数和x
		}
		else {
			printf("%dx^%d", current->coef, current->exp); // 其他情况正常输出
		}
		current = current->next;
	}
	printf("\n");

	PolyAdd(pa, pb);
	printf("Add pa:");

	// 输出相加后的多项式
	current = pa->next; // 从头节点的下一个开始
	while (current != NULL) {
		if (current->coef > 0 && current != pa->next) {
			printf("+"); // 如果系数为正且不是第一个项，输出加号
		}
		if (current->exp == 0) {
			printf("%d", current->coef); // 指数为0时只输出系数
		}
		else if (current->exp == 1) {
			if (current->coef == 1)
			{
				printf("x");
			}
			else
				printf("%dx", current->coef); // 指数为1时只输出系数和x
		}
		else {
			printf("%dx^%d", current->coef, current->exp); // 其他情况正常输出
		}
		current = current->next;
	}
	printf("\n");

	return 0;
}




