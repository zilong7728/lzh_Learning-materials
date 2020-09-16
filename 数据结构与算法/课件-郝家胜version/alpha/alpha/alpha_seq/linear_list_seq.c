/*************************************************************************
 *  学号：
 *  姓名：
 *************************************************************************
 *                      《软件技术基础》上机实践 （二）
 *
 *  作业名称: Alpha 问题的顺序表实现
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

#define MAX_LENGTH 64

/* 线性表的表示 */
struct list_t
{
     int *data;  /* 节点类型及存储缓冲区首地址 */
     int length; /* 当前节点个数 */
     int max_length;   /* 最大节点个数 */
};


/* 创建一个空的线性表 */
LIST create_list()
{
     LIST list = (LIST) malloc(sizeof(LIST));
     list->data = (int*) malloc(sizeof(int) * MAX_LENGTH);
     list->length = 0;
     list->max_length = MAX_LENGTH;

     return list;
}

/* 获取线性表的长度 */
int   list_length(LIST list)
{
     return 0;
}

/* 获取指定位置上的节点，不存在则返回 E_NODE_NOT_FOUND */
int   list_get   (LIST list, int pos)
{


     return (list->data[pos]);
}


/* 将数值x插入到线性表的位置 pos 上 */
int   list_insert(LIST list, int pos, int x)
{
     int length, i;

     assert(list != NULL);

     length = list->length;
     if (length == list->max_length)
          return E_NODE_NOT_FOUND;

     if ((pos < 0) || (pos > length))
          return E_NODE_NOT_FOUND;

     for (i = length - 1; i >= pos; i--)
          list->data[ i+1 ] = list->data[i];

     list->data[ pos ] = x;

     list->length += 1;

     return E_SUCCESS;
}

/* 删除线性表中指定位置上的节点，位置不存在则返回 E_NODE_NOT_FOUND */
int   list_delete(LIST list, int pos)
{


     return E_SUCCESS;
}
