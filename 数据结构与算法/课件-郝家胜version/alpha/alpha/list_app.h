#ifndef __LIST_APP_H_INCLUDED__
#define __LIST_APP_H_INCLUDED__


/*************************************************************************
 * 函数前向声明
 *************************************************************************/

/* 遍历线性表，依次打印结点的值 */
void display_list(LIST list);

/* 对线性表排序 */
void sort_list(LIST list);

/* 查找线性表，返回相应的位置 */
int search_list(LIST list, int x);

/* 删除线性表中重复出现的结点 */
void purge_list  (LIST list);



#endif // __LIST_APP_H_INCLUDED__
