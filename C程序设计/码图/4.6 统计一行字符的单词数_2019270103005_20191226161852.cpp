/*输入一行字符，统计其中包括多少单词，单词之间用空格分隔。

输入输出格式要求：
	输入格式：a b c d回车（空格可在任意位置，列如行头行尾可能会有空格。另外数字和字母一样，也可作为单词）
	输出格式：单词数
	输入的字符串长度最长为256个字符
例如：
输入：（空格）a a 112 c（空格）回车
输出：4*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[260];
	gets_s(a, 260);
	int i = 0;
	while (a[i] == ' ')
	{
		i++;
	}
	char* p;
	p = &a[i];
	int j = 0;
	while ((*p) != '\0')
	{
		if (*(p - 1) == *p && *p == ' ')
		{
			p++;
			continue;
		}
		if (*p == ' ')
		{
			j++;
		}
		p++;
	}
	if (*(p - 1) != ' ') j++;
	printf("%d", j);
	return 0;
}
