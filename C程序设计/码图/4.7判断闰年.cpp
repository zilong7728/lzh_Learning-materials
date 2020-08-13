/*输入一个年份，判断这一年是不是闰年*/ 
#include<stdio.h>
int main()
{
	int year,a=4,b=100,c=400;
	scanf("%d",&year);
	if((year%a==0&&year%b!=0)||(year%c==0))
	{
		printf("yes"); 
	}
	else
	{
		printf("no");
	 } 
	return 0;
 } 
