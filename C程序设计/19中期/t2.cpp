/*将一个字符插入到一个字符串中（字符已经从小到大排序）中
  （字符和字符串由输入得到）*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i=0,j=0;
	char a[105],b[105],c;
	
	//输入字符串和字符 
	gets(a);
	scanf("%c",&c);
	
	//字符插入字符串 
	while(a[i]!='\0')
	{
		if(c<=a[i])
		{
			b[j]=c;
			c=127;
		}
		else
		{
			b[j]=a[i];
			i++;
		}
		j++;
	}
	
	//对于c大于a中任意一个
	int e,f;
	e=strlen(a);
	f=strlen(b);
	if(e==f)
	{
		b[j]=c;
	}
	
	//输出
	for(i=0;b[i]!='\0';i++)
	{
		printf("%c",b[i]);
	} 
	
	return 0;
}
