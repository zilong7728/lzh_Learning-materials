#ifndef __LINEAR_LIST_H_INCLUDED__
#define __LINEAR_LIST_H_INCLUDED__

/*************************************************************************
 *  线性表的抽象数据类型
 *************************************************************************
 *
 *     该头文件中声明了线性表的抽象数据类型，包括类型名称和基本操作。线
 * 性表应用的客户代码均应在此基础之上进行设计和实现。
 *
 *     由于此文件中屏蔽了任何实现的具体细节，使得客户代码不依赖于线性表
 * 的具体表示和实现方式。
 *
 *************************************************************************
 *
 *  Copyright 2010-2013 by HAO Jiasheng <haojiasheng@gmail.com>
 *
 ************************************************************************/

/* 声明 list_t 为结构体类型，但隐去了其具体表示，实现信息隐藏 */
typedef struct list_t* LIST;

/* 定义错误信息码 */
#define E_NODE_NOT_FOUND -1
#define E_SUCCESS        0

/* 创建一个空的线性表 */
LIST create_list();

/* 获取线性表的长度 */
int   list_length(LIST list);

/* 获取指定位置上的节点，不存在则返回 E_NODE_NOT_FOUND */
int   list_get   (LIST list, int pos);

/* 将数值x插入到线性表的位置 pos 上 */
int   list_insert(LIST list, int pos, int x);

/* 删除线性表中指定位置上的节点，位置不存在则返回 E_NODE_NOT_FOUND */
int   list_delete(LIST list, int pos);

#endif // __LINEAR_LIST_H_INCLUDED__
