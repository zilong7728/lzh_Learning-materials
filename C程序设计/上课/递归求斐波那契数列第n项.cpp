#include<stdio.h>
#include<stdlib.h>
int fi(int n)
{
	if (n < 0)
	{
		return -1;
	}
	else if (n == 1 || n == 2)
	{
		return 1;
	}
	else if (n > 2)
	{
		return fi(n - 1) + fi(n - 2);
	}
}
int main()
{
	int a, b;
	scanf_s("%d", &a);
	b = fi(a);
	printf("%d", b);
	return 0;
}
