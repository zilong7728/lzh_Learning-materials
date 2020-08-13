/*倒序输出字符数组*/ 
#include<stdio.h>
#define LEN 50
int main()
{
	char str[LEN]={0};
	int len,i;
	gets(str);//gets会包含空格，scanf不会
	len=strlen(str);
	for(i=len-1;i>=0;i--)
	{
		putchar(str[i]);
	}
	return 0;
}
