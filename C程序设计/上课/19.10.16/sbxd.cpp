#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[10],i,j,z;
	for(i=0;i<=9;i++)
	{
		if(i<9)
		{
			scanf("%d ",&a[i]);
		}
		else scanf("%d",&a[9]);
	}
	for(i=0;i<=8;i++)
	{
		for(j=i+1;j<=9;j++)
		{
			if(a[i]>a[j])
			{
				z=a[i];
				a[i]=a[j];
				a[j]=z;
			}
		}
	}
	for(i=0;i<10;i++)
	{
		if(i<9)
		{
			printf("%d,",a[i]);
		}
		else printf("%d",a[i]);
    }
    return 0;
 } 
