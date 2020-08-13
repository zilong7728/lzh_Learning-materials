#include<stdio.h>
int main()
{
	//输入数的个数
	int x;
	scanf("%d",&x);
	
	//输入数组 a
	int a[x];
	for(int i=0;i<x;i++)
	{
		scanf("%d",&a[i]);
	} 
	
	//输入前 n个元素中找出第 k小的值 
	int n,k;
	scanf("%d %d",&n,&k);
	
	//找到前 n个元素中第 k小的值
	for(int i=n+1;i<x;i++)
	{
		a[i]=0;
	} 
	
	//排序
	int i,j,b;
	for(i=0;i<x;i++)
	{
		for(j=i+1;j<x;j++)
		{
			if(a[i]>a[j])
			{
				b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	} 
	
	//输出
	printf("%d",a[10-n+k]);
	
	return 0; 
}
