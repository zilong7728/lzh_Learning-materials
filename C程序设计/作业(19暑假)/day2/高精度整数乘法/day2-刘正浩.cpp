/*高精度整数乘法*/
#include<stdio.h>
#include<string.h>
int main()
{
	char a[100], b[100],x[100],y[100];
	scanf_s("%s\n%s", a, 100, b, 100);
	int m = 0, n = 0;
	while(a[m] != 0)
	{
		m++;
	}
	while(b[n] != 0)
	{
		n++;
	}
	int i, j;
	for (i = 0, j = m - 1; i < m; i++, j--)
	{
		x[i] = a[j] - 48;//灵感来自于郭导的上课内容// 
	}
	for (i = 0, j = n - 1; i < n; i++, j--)
	{
		y[i] = b[j] - 48;//此时y[1]为个位 ，y[2]为十位，以此类推// 
	}
	int c[200];
	for (i = 0; i < 200; i++)
	{
		c[i] = 0;
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			c[i + j] = c[i + j] + x[i] * y[j];
		}
	}
	for (i = 0; i < m + n; i++)
	{
		if (c[i] >= 10) {
			c[i + 1] = c[i + 1] + c[i] / 10;
			c[i] = c[i] % 10;
		}
	}
	for (j = 99; j > 0; j--)
	{
		if (c[j] != 0)
			break;
	}
	for (i = j; i >= 0; i--)
	{
		printf("%d", c[i]);
	}
	return 0;
}