#include<stdio.h>
int main()
{
	//输入人数 
	int a;
	scanf("%d",&a);
	
	//name存储姓名，str存储最长的姓名
	char name[a][20],str[20]; 
	int i,k,number,len=0,count=0;
	printf("enter the number of students");
	i=scanf("%d",&number);
	
	//输入错误
	if(i<1)
	{
		printf("scanf error");
		return -1;
	}
	
	//找出最长的名字的长度 
	for(i=0;i<number;i++)
	{
		scanf("%s",name[i]);
		k=strlen(name[i]);
		if(len<=k)
		{
			len=k;
		}
	} 
	
	//找M开头的姓名并输出 
	for(i=0;i<number;i++)
	{
		if(name[i][0]=='M')
		{
			count++;
			printf("%s\n",name[i]);
		}
	}
	
	//输出最长的名字
	int b;
	for(i=0;i<20;i++)
	{
		b=strlen(name[i]);
		if(b==len)
		{
			printf("%s",name[i]);
		}
	} 
	
	return 0;
}
