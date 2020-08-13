/*接收输入的一个字符串(无空格、制表符等)，
原封不动输出该字符串，最后必须输出回车。
最长输入20个有效字符（不包括回车）。
例如输入：apple 输出：apple
输入：test2test* 输出：test2test* */

#include<stdio.h>
int main()
{
	char c[20];
	scanf("%s",c,20);
	for(int i=0;c[i]!='\0';i++)
	{
	    printf("%c",c[i]);
	} 
    printf("%s\n","\0");
	return 0;
} 
