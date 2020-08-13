//老师，我在main里写了个链表，现在想输出一下每个结点的数据看看对不对，，但是这个代码咋只能输出首尾两个呢/衰
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	typedef struct node
	{
		int data;
		struct node *next;
	}Node,*List;//定义一个结构类型，并且定义一个叫做Node的node型结构，以及指向结构node结构的指针next，该指针指向链表的下一个元素
	List S=NULL, L;//定义指向node结构的两个指针，L用来指向第一个元素,S用于指向后面的元素
	int number, n;
	printf("链表个数为\n");
	scanf_s("%d",&number);
	if (number == 0)
	{
		L = NULL;
		return -1;
	}
	else
	{
		printf("请输入第1个数:\n");
		scanf_s("%d", &n);
		L = (List)malloc(sizeof(Node));
		if(L==NULL)
		{
			printf("生成失败\n");
			return -1;
		}

		L->next = NULL;//当只有一个元素时，第一个指针指向空指针
		L->data = n;

		for (int i = 1; i < number; i++)
		{
			S = (List)malloc(sizeof(Node));
			if (S == NULL)
			{
				printf("生成失败\n");
				return -1;
			}
			printf("请输入第%d个数:\n", i+1);
			scanf_s("%d", &n);
			S->data = n;
            S->next = L;//最后一个结点指向第一个结点
			L->next = S;//第一个结点指向最末的结点
        }
		
	}
	printf("链表生成成功\n");
	List p=S->next,q=p;
	printf("%d\n", p->data);
	p = p->next;
	while (p!=(q))
	{
		printf("%d\n",p->data);
		p = p->next;
	}
	system("pause");
	return 0;
}

