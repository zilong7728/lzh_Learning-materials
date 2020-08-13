/*输入一个字符串，删除其中的英文字母（大小写）和数字字符；
  对连续出现的相同字符，将其缩减为一个*/ 
#include<stdio.h>
int main()
{
	int i,j=0;
	char a[105],b[105]={'\0'};
	scanf("%s",a);
	
	//删除英文和数字
	for(i=0;i<=104;i++)
	{
		if((a[i]>=48)&&(a[i]<=57)||(a[i]>=65)&&(a[i]<=90)||(a[i]>=97)&&(a[i]<=122))
		{
			continue;
		}
		else
		{
			b[j]=a[i];
			j++;
		}
	}
	
	//输出缩减后的字符串
	if(j>0)
	{
		printf("%c",b[0]);
		for(j=1;b[j]!='\0';j++)
		{
			if(b[j]!=b[j-1])
				printf("%c",b[j]);
		}
	}
	return 0;
}
