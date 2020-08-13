#include<stdio.h>
int max(int x, int y) {
	int z;
	if (x > y)
	z = x;
	else z = y;
	return z;
}
int main()
{
	int a, b, c;
	scanf("%d %d", &a, &b);
	c = max(a, b);
	printf("max is %d\n", c);
	return 0;
}
