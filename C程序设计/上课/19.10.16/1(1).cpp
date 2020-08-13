#include<stdio.h>
int main()
{
	int a;
	int max,min;
	for(a=2000000000,max=a-1;a>max;a++)
	{
		max=a;
	}
	for(a=-2000000000,min=a+1;a<min;a--)
	{
		min=a;
	}
	printf("%d\t%d",max,min);
	return 0;
}
