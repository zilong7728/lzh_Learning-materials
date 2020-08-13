/*使用循环 语句（for或while）打印十个*号
  输出：**********回车*/ 
#include<stdio.h>
int main ()
{
	for(int i=0;i<=9;i++)
	{
		if(i<9)
		{
			printf("*");
		}
		else
		{
			printf("*\n");
		}
	}
	return 0;
}
