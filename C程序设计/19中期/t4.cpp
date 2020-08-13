/*求满足n^k<=m的k的最大值，其中n和m由输入得到*/ 
#include<stdio.h>
int main()
{
	int n,m,p=1,k=0;
	
	//输入n,m
	printf("请按顺序输入n，m"); 
	scanf("%d %d",&n,&m);
	
	//判断k的最大值
	while(p<m)
	{
		p*=n;
		k++;
	} 
	
	//输出k
	printf("%d",k-1);
	
	return 0; 
}
