/*************************************************************************
 *                      《软件技术基础》上机实践 （二）
 *************************************************************************
 *  作业名称: Alpha 问题的顺序表实现
 *
 *  作业描述:
 *      从键盘接受用户输入若干个自然数，创建一个有序线性表。该有序表可以
 *  为非减序，也可以为非增序，但要求表中不能出现重复的元素。另外，还可以
 *  从键盘接受用户输入，并从该有序表中删除该输入对应的结点。
 *      其中，线性表的抽象数据类型的顺序存储实现已经在 linear_list.c 中给
 *  完整的实现，并且输出有序表、删除重复的元素这些建立在线性表的抽象数据
 *  类型之上的运算代码也已在文件 list_app.c 中给出了示例。
 *
 *  作业要求：
 *      根据文件 linear_list.h 中声明的线性表的抽象数据类型，以及 list_app.h
 *  中声明的接口，实现线性表的插入排序和二分查找抽象运算，即完成文件 list_app.c。
 *      最终在教学网络平台上提交实现完整的 list_app.c 文件即可，要求必
 *  须具有适当的注释和良好的代码风格。
 *
 *  提交说明：
 *      提交材料：完整的 list_app.c 源代码（包括注释）；
 *
 */

/*************************************************************************
 *  学号：
 *  姓名：
 *************************************************************************
 *                      《软件技术基础》上机实践
 *
 *  作业名称:
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
#include <assert.h>
#include "linear_list.h"
#include "list_app.h"

/*************************************************************************
 * 函数实现
 *************************************************************************/

/*
 * 功能描述：采用简单插入排序算法对线性表进行排序
 * 输    入：线性表指针，结点值
 * 输    出：实际插入的位置
 */
void sort_list(LIST list)
{
     int i, j, k;
     int length;

     assert(NULL != list);
     length = list_length(list);

     for (j = 1; j < length; j++)
     {
          k = list_get(list, j);
          i = j - 1;
          while ((i >= 0) && list_get(list, i) > k)
               i--;
          list_delete(list, j);
          list_insert(list, i+1, k);
     }
}

/*
 * 功能描述：采用二分查找算法对线性表进行检索
 * 输    入：线性表指针，结点值
 * 输    出：相应的位置
 */
int search_list(LIST list, int x)
{
     int low, high, mid;

     /*给线性表的起始下标和最终下标赋值*/
     low = 0;
     high = list_length(list) - 1;

     /*从最中间的元素开始比较，依次循环*/
     while(low <= high)
     {
          mid = (low + high)/2;
          if(list_get(list, mid) == x)
          {
               /*查找成功并输出相应的位置*/

               return mid;
          }
          else if(list_get(list, mid) < x)
               low = mid + 1;
          else
               high = mid - 1;
     }
     /*查找失败*/

     return E_NODE_NOT_FOUND;
}

/*
 * 功能描述：删除线性表中重复出现的结点，即对于值相同的结点，仅
 *           保留一个
 * 输    入：线性表指针
 * 输    出：无
 */
void purge_list(LIST list)
{
     int length, i;

     assert(NULL != list);
     i = 0;
     length = list_length(list);

     /* 由于线性表已经有序，重复出现的元素是相邻的，因此只需
      * 检查紧邻的后一个结点并删除即可。*/
     while ( i < length) {
          i++;
          while ((i < length) && (list_get(list, i) == list_get(list, i-1))) {
               list_delete(list, i);
               length -= 1;
          }
     }

     return;
}

/*
 * 功能描述：遍历线性表，依次打印结点的值，打印形式如
 *           ``(x1, x2, ..., xn)''
 * 输    入：线性表指针
 * 输    出：无
 */
void display_list(LIST list)
{
     int length;
     int i;

     assert(NULL != list);
     length = list_length(list);

     printf("\n>> L：(");
     /* 遍历线性表，依次数出各结点 */
     for (i = 0; i < length; i++)
     {
          printf("%d", list_get(list, i));
          /* 如果不是最后一个结点，打印``，''*/
          if (i < length - 1)
               printf(", ");
     }

     printf(")\n");
}

/* Ends */
