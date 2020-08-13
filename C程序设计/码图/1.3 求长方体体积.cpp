/*求长方体体积
1 输入三个整数,空格间隔;
2 运用体积计算公式：V=a*b*c；
3 输出体积。
*/ 
#include<stdio.h>
int main()
{
	int a,b,c,volume;
	scanf("%d %d %d",&a,&b,&c);
	volume=a*b*c;
	printf("%d",volume);
	return 0;
 } 
