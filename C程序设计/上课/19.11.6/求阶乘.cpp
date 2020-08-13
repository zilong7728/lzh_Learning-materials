#include<stdio.h>
int main()
{
	int n,a=1,b=0,c=0;
	scanf("%d",&n);
	a=n;
	if(n<1||n>10)
	{
		printf("error");
	}
	else
	{
		for(int j=n-1;j>0;j--)
		{
			a*=j;
		}
		b=a;
		for(int i=n;i>0;i--)
		{
			b=b/i;
			c=c+b;
		}
		c=c+a;
	}
	printf("%d",c-1);
	return 0;
}
