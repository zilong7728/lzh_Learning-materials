/*题目分析：输入字符串a，b。a包含n个字符。写一函数，
将字符串a中的第p到q个字符插入到字符串b第k个字符后输出。
用指针方法处理。
例如：输入a是abcdefg，b是tttt。
p=3，q=5，k=2，则应输出：ttcdett。 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void ins(char a[],char b[],int m,int n,int p)
{
	char* x, * y;
	x = (char*)malloc(sizeof(char));
	y = (char*)malloc(sizeof(char));
	x = &a[0];
	for (int i = 0; i < p; i++)
	{
		printf("%c", *x);
		x++;
	}
	y = &b[m - 1];
	for (int i = 0; i < n - m; i++)
	{
		printf("%c", *y);
		y++;
	}
	int k;
	k = strlen(a);
	for (int i = 0; i < k - p; i++)
	{
		printf("%c", *x);
		x++;
	}
}
int main()
{
	char a[105], b[105];
	printf("input char'a'\n");
	scanf_s("%s", a, 105);
	printf("input char'b'\n");
	scanf_s("%s", b, 105);
	int m, n, p;
	printf("input controlling nums");
	scanf_s("%d %d %d", &m, &n, &p);
	ins(a, b, m, n, p);
	return 0;
}
