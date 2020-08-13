#include<stdio.h>
int main()
{
	int x,a,b,c;
	scanf("%d",&x);
	a=(x/10)/10;
	b=(x/10)%10;
	c=x%10;
	printf("%d",a+b+c);
	return 0;
}
