#include<stdio.h>
int main()
{
	void swap_right(int* a, int* b);
	int x, y, z;
	x = 5;
	y = 6;
	swap_right(&x, &y);
	printf("%d %d", x, y);
	

	return 0;
}

int add_int(int a, int b)
{
	int c;
	c = a + b;
	return c;
}

float add_float(float a, float b)
{
	float c;
	c = a + b;
	return c;
}

void swap_wrong(int a, int b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

void swap_right(int* a, int* b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void print_star()
{
	printf("*");
}