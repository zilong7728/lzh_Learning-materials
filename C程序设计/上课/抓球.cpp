/*从3个红球、5个白球、6个黑球中任意取出8个，且其中要有红球和白球
  要求：输出所有可能情况的数量和每种球的数量*/
#include<stdio.h>
#include<stdlib.h>

typedef struct ballnum
{
	int red; int white; int black;
}ballnumbs;

int sec(ballnumbs* b)
{
	int n = 0, i, j;
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 5; j++)
		{
			b[n].red = i;
			b[n].white = j;
			b[n].black = 8 - i - j;
		}
	}
	return n;
}

int main()
{
	ballnumbs a[20];
	int num, i;
	num = sec(a);
	printf("%d", num);
	for (i = 1; i <= num; i++)
	{
		printf("%d %d %d\n", a[i].red, a[i].white, a[i].black);
	}
	return 0;
}
