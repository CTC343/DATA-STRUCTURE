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
	int c, e, last_exp = -1; // ��ʼ�� last_exp Ϊ��Чֵ
	head = (Polynode*)malloc(sizeof(Polynode));
	rear = head;

	scanf("%d,%d", &c, &e);
	while (c != 0)
	{
		// ����������ָ���Ƿ�С�ڻ������һ��ָ��
		while (e <= last_exp)
		{
			scanf("%d", &e); // ֻ��������ָ��
		}

		s = (Polynode*)malloc(sizeof(Polynode));
		s->coef = c;
		s->exp = e;
		rear->next = s;
		rear = s;

		last_exp = e; // ���� last_exp Ϊ��ǰ���ָ��
		scanf("%d,%d", &c, &e);
	}
	rear->next = NULL; // �������һ�����һ��ָ��Ϊ NULL
	return (head); // ���ض���ʽ�����ͷָ��
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
	Polylist pa = PolyCreate(); // ����pa
	printf("please input pa,end with 0:\n");
	printf("pa:");

	// ���paʽ��
	Polynode* current = pa->next; // ��ͷ�ڵ����һ����ʼ
	while (current != NULL) {
		if (current->coef > 0 && current != pa->next) {
			printf("+"); // ���ϵ��Ϊ���Ҳ��ǵ�һ�������Ӻ�
		}
		if (current->exp == 0) {
			printf("%d", current->coef); // ָ��Ϊ0ʱֻ���ϵ��
		}
		else if (current->exp == 1) {
			if (current->coef == 1)
			{
				printf("x");
			}
			else
				printf("%dx", current->coef); // ָ��Ϊ1ʱֻ���ϵ����x
		}
		else {
			printf("%dx^%d", current->coef, current->exp); // ��������������
		}
		current = current->next;
	}
	printf("\n");

	Polylist pb = PolyCreate(); // ����pb
	printf("please input pb,end with 0:\n");
	printf("pb:");

	// ���pbʽ��
	current = pb->next; // ��ͷ�ڵ����һ����ʼ
	while (current != NULL) {
		if (current->coef > 0 && current != pb->next) {
			printf("+"); // ���ϵ��Ϊ���Ҳ��ǵ�һ�������Ӻ�
		}
		if (current->exp == 0) {
			printf("%d", current->coef); // ָ��Ϊ0ʱֻ���ϵ��
		}
		else if (current->exp == 1) {
			if (current->coef == 1)
			{
				printf("x");
			}
			else
				printf("%dx", current->coef); // ָ��Ϊ1ʱֻ���ϵ����x
		}
		else {
			printf("%dx^%d", current->coef, current->exp); // ��������������
		}
		current = current->next;
	}
	printf("\n");

	PolyAdd(pa, pb);
	printf("Add pa:");

	// �����Ӻ�Ķ���ʽ
	current = pa->next; // ��ͷ�ڵ����һ����ʼ
	while (current != NULL) {
		if (current->coef > 0 && current != pa->next) {
			printf("+"); // ���ϵ��Ϊ���Ҳ��ǵ�һ�������Ӻ�
		}
		if (current->exp == 0) {
			printf("%d", current->coef); // ָ��Ϊ0ʱֻ���ϵ��
		}
		else if (current->exp == 1) {
			if (current->coef == 1)
			{
				printf("x");
			}
			else
				printf("%dx", current->coef); // ָ��Ϊ1ʱֻ���ϵ����x
		}
		else {
			printf("%dx^%d", current->coef, current->exp); // ��������������
		}
		current = current->next;
	}
	printf("\n");

	return 0;
}




