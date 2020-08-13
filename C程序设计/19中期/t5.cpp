/*判断一个算术表达式中的小括号是否配对
  算术表达式由键盘输入，操作数全为正整数；
  运算符为二元运算符：+，-，*，/，% */ 
#include<stdio.h>
int main()
{
	char a[30];
	scanf("%s",a);
	int b=0;
	for(int i=0;i<30;i++)
	{
		if(a[i]=='(')
		{
			b++;
		}
		else if(a[i]==')')
		{
			b--;
		}
		if(b<0)
		{
			printf("error");
			return 0;
		}
	}
	
	if(b==0)
	{
		printf("no problem, my old brother");
	}

	else if(b>0)
	{
		printf("error");
	}
	
	return 0;
}
