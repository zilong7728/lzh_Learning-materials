#include<stdio.h>
int main()
{
	int x,i;
	scanf("%d",&x);
	for(i=0;x>0;i++)
	{
		x=x/10;
	}
	printf("%d",i);
}
