#include<stdio.h> //standard input output
#include<stdlib.h> // standard library
int main()
{
	int* p;
	int i;
	char a[100];
	int n;
	scanf("%d", &n);
	p = (int*)malloc(n * sizeof(int));

	for (i = 0; i < 5; i++)
		* (p + i) = i;
	for (i = 0; i < 5; i++)
		printf("%d ", *(p + i));
	printf("%d", p[1]);

	return 0;

}