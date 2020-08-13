/*1 输入一个整数;
2 若该数为正数，则其绝对值取该数的值,否则，其绝对值取该数的相反数值；
3 输出其绝对值。*/ 
#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d",&a);
	if(a>=0)
	  b=a;
	else
	  b=-a;
	printf("%d",b);
	return 0;
 } 
