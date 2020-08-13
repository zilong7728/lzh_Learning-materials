#include<stdio.h>
int main()
{
	int a[1000];
	for(int i=1;i<=1000;i++)
	{
		a[i]=i;
	}
	for(int i=1;i<=1000;i++)
	{
		printf("%d ",a[i]);
		if(i%10==0)
		{
			printf("\n");
		}
	}
	return 0;
}
