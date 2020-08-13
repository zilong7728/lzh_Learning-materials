#include<stdio.h>
int main()
{
	int a,b,c=0,i=0,j=0;
	scanf("%d",&b);
	a=b;
	while(a!=0)
	{
		a=a/10;
		i++;
	}
	while(j<=i)
	{
		c=c+b%10;
		b=b/10;
		j++;
	}
	printf("%d",c);
	return 0;
}
