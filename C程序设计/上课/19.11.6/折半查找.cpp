#include<stdio.h>
#include<stdlib.h>
int main()
{
	//输入数组长度和 
	int len;
	scanf("%d",&len);
	int data[len+5];
	printf("please input your data\n");
	for(int i=0;i<len;i++)
	{
		scanf("%d",&data[i]);
	}
	
	//按从小到大排序数组data中的数 
	int z;
	for(int i=1;i<len;i++)
	{
		for(int j=0;j<len-i;j++)
		{
			if(data[j]>data[j+1])
			{
				z=data[j+1];
				data[j+1]=data[j];
				data[j]=z;
			}
		}
	}
	
	//折半查找数a是否在数组data中 
	int x,a,b,k;
	printf("please input the number you want to search\n");
	scanf("%d",x);
	a=len;
	b=0;
	while(a<=b)
	{
		k=(a+b)/2;
		if(x=data[k])
		{
			printf("%d\n",k);
			return 0;
		}
		else if(x>data[k])
		{
			a=k+1;
		}
		else if(x<data[k])
		{
			b=k-1;
		}
	}
	printf("No\n");
	return 0;
	
}
