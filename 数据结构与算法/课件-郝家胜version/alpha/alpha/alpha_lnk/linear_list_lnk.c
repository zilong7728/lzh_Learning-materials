/*************************************************************************
 *  学号：
 *  姓名：
 *************************************************************************
 *                      《软件技术基础》上机实践 （三）
 *
 *  作业名称: Alpha 问题的链接表实现
 *
 *  完成情况描述:
 *
 *
 *************************************************************************
 *
 *  Copyright 2010-2013 by HAO Jiasheng <haojiasheng@gmail.com>
 *
 ************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "../linear_list.h"

/* 线性表的表示 */
struct list_t
{
	int length;
	/* 带头结点的链表结构 */
	struct node_t *head;
};

struct node_t
{
    int data;
    struct node_t *next;
};

/////////////////////////////////////////////////////////////////////////////
/* 动态创建一个新的节点，并做初始化 */
static struct node_t* _create_node()
{
    struct node_t* node;
    /* 初始化头结点 */
    node = (struct node_t *)malloc(sizeof(struct node_t));
    node->data = -1;
    node->next = NULL;

    return node;
}

/* 获取指定位置上的前一个节点，不存在则返回 NULL */
static struct node_t* _get_prevnode(LIST list, int pos)
{
	struct node_t *node = NULL;

    /* 指向头结点 */
	node = list->head;

	/*循环到指定位置的前一个节点时pos变为1，不再往后执行*/
	while(node != NULL && pos-- > 0)
	{
		node = node->next;
	}

	return node;
}

/////////////////////////////////////////////////////////////////////////////

/* 创建一个空的线性表 */
LIST create_list()
{
	struct list_t *list ;

    list = (struct list_t *)malloc(sizeof(struct list_t));
	list->length = 0 ;
	/*获取线性链表的头结点指针*/
	list->head = _create_node();

    return list;
}

/* 获取线性表的长度 */
int   list_length(LIST list)
{

    return 0;
}


/* 获取指定位置上的节点，不存在则返回 E_NODE_NOT_FOUND */
int   list_get(LIST list, int pos)
{


    return 0;
}

/* 将数值x插入到线性表的位置 pos 上 */
int   list_insert(LIST list, int pos, int x)
/*
 * 如果 pos < length，说明线性表中存在比x大的节点
 * 否则，pos == length, 此时x是最大结点，应添加到表的末尾
 */
{
	struct node_t *prev,*new_node ;

	assert(NULL != list);
	/* 判断pos是否有效:pos必须不小于0,并且不大于链表长度 */
	if(pos < 0 || pos > list->length)
	{
		return E_NODE_NOT_FOUND ;
	}

    /*新建一个节点存放要插入的元素*/
	new_node = _create_node();
	new_node->data = x;

	prev = _get_prevnode(list, pos);

	/*将新插入节点的next指针指向原来链表中指定位置节点的地址*/
	new_node->next = prev->next ;
	/*将指定位置前一个节点的next指针指向新插入节点的地址*/
	prev->next = new_node ;

    /*将线性链表长度自动加1*/
	list->length += 1;

	return E_SUCCESS ;
}

/* 删除线性表中指定位置上的节点，位置不存在则返回 E_NODE_NOT_FOUND */
int   list_delete(LIST list, int pos)
{


	return E_SUCCESS ;
}
