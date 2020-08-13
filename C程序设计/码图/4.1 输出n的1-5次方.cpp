/*输入整数n，然后输出n的1-5次方(空格区分)，最后必须输出回车
例如输入-1，输出-1 1 -1 1 -1回车*/

#include<stdio.h>
int main()
{
	int a,b=1,i;
	scanf("%d",&a);
	for(i=1;i<=5;i++)
	{
		b*=a;
		if(i<5)
		{
			printf("%d ",b);
		}
		else
		printf("%d\n",b);
	}
	return 0;
}
