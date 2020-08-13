/*温度转换
已知华氏温度f与摄氏温度c之间的转换公式是：
C=5/9*(F-32)
编写程序，将用户输入的摄氏温度转换为华氏温度，并输出结果。
温度要求均为整数
*/ 
#include<stdio.h>
int main()
{
	int c,f,a=5,b=9;
	scanf("%d",&c);
	f=32+(c*b)/a;
	printf("%d",f);
	return 0;
}
	
