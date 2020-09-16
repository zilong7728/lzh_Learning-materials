/*************************************************************************
 *                      《软件技术基础》上机实践 （二）
 *************************************************************************
 *  作业名称: Alpha 问题的抽象数据类型实现
 *
 *  作业描述:
 *      从键盘接受用户输入若干个自然数，创建一个有序线性表，并可以对线
 *  性表进行操作。该有序表可以为非减序，也可以为非增序。
 *      线性表的抽象数据类型的接口定义在 linear_list.h 中已给出，同时基
 *  于这些接口的线性表抽象运算（如插入排序、二分查找、输出有序表等）也
 *  已在文件 list_app.c 中实现。
 *      线性表的这个抽象数据类型的具体实现方式可以采用顺序表或者链接表，
 *  分别在源文件 linear_list_seq.c 和 linear_list_lnk.c 中，其中已提供部
 *  分操作实现作为参考。
 *
 *  作业要求：
 *      根据文件 linear_list.h 中声明的线性表的抽象数据类型，完成线性表
 *  抽象数据类型的两种不同具体实现。
 *     （1）顺序表实现：在 linear_list_seq.c 实现顺序表的基本操作，包括
 *  指定位置元素的获取、定位、插入和删除，即完成文件 linear_list_seq.c。
 *     （2）链接表实现：在 linear_list_lnk.c 实现链接表的基本操作，包括
 *  指定位置元素的获取、定位、插入和删除，即完成文件 linear_list_lnk.c。
 *
 *  提交说明：
 *      提交材料：
 *     （1）对整个程序中抽象数据类型的分析;
 *     （2）完整的 linear_list_seq.c 源代码（包括注释）；
 *     （3）完整的 linear_list_lnk.c 源代码（包括注释）。
 *
 *************************************************************************
 *
 *  Copyright 2010-2016 by HAO Jiasheng <haojiasheng@gmail.com>
 *
 ************************************************************************/
#include <stdio.h>
#include <assert.h>
#include "linear_list.h"
#include "list_app.h"

#define EOL -1           /* End Of List，输入结束标志 */


void do_purge(LIST list)
{
     /* 删除重复出现的元素 */
     printf("\n>> 删除重复出现的元素...\n");
     purge_list(list);
     /* 输出线性表 */
     display_list(list);
}

void do_find(LIST list)
{
     int x, i;

     /*采用二分查找元素*/

     printf ("\n>> 输入采用二分查找的元素：");
     scanf("%d",&x);

     i = search_list(list,x);
     /* 输出结果 */
     if ( i != E_NODE_NOT_FOUND )
          printf("Found at the position: %d\n", i);
     else
          printf("Not found.\n");

}

void do_delete(LIST list)
{
     int x, i;

     /* 获取用户输入，并将线性表中对应的结点删除 */
     printf("\n>> 输入要删除的元素：");
     scanf("%d", &x);

     /* 先定为值为 x 的结点，得到其位置，然后根据该位置执行删除操作 */
     i = search_list(list, x);
     if (E_SUCCESS != list_delete(list, i))
          printf("Delete failed: node not found.\n");
     /* 输出线性表 */
     display_list(list);
}


/*************************************************************************
 * 主函数
 *************************************************************************/

/*
 * 功能描述：主函数，获取用户输入，并作相应处理，打印输出
 * 输    入：系统默认
 * 输    出：0
 */

int main(int argc, char *argv[])
{
     LIST list;
     int x;
     int i;


     /* 创建一个空的线性表 */
     list = create_list();
     assert(NULL != list);

     /* 获取用户输入，并插入到线性表中适当的位置 */
     printf("\n>> 输入若干个自然数，以 %d 结束输入：\n", EOL);

     i = 0;
     while (1) {
          printf(" x[%d] = ", i);
          scanf("%d", &x);
          if (EOL == x)
               break;

          list_insert(list, list_length(list), x);
          /* 对线性表进行排序 */
          sort_list(list);
          /* 输出线性表 */
          display_list(list);

          i++;
     }

     while (1) {
          printf("\n>> [0-> 退出；1-> 输出线性表；2-> 删除重复结点; 3-> 查找结点；4-> 删除结点]：");
          scanf("%d", &x);

          if (x == 0) break;

          switch (x)
          {
          case 1:
               display_list(list);
               break;
          case 2:
               do_purge(list);
               break;
          case 3:
               do_find(list);
               break;
          case 4:
               do_delete(list);
               break;
          }
     }

     return 0;
}

/* Ends */

