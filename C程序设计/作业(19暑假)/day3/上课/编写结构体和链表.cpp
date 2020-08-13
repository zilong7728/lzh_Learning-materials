#include<stdio.h>
#include<stdlib.h>
int main()
{
	struct MyStruct
	{
		char name[10];
	};


	typedef struct MyStruct MyStruct;
	MyStruct first;
	scanf("%s", first.name);
	printf("%s", first.name);
	return 0;

	struct LinkList
	{
		int value;
		struct LinkList* pointer_pre;
		struct LinkList* pointer_next;
	};
	typedef struct LinkList LinkList;
	LinkList* first_node, second_node;
	first_node = (LinkList*)malloc(sizeof(LinkList));
	second_node = (LinkList*)malloc(sizeof(LinkList));
	first_node->pointer_next = second_node;
	first_node->pointer_pre = NULL;
	second_node->pointer_pre = first_node;
	second_node->pointer_next = NULL;
}