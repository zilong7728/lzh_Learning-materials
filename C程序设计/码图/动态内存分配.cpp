/*编写程序，输入整数n，动态分配保存n个整数的存储器，然后输入n个整数保存到存储器中。最后，将这n个整数从小到大输出。
例如：
输入如下：
10回车
10 9 8 7 6 5 4 3 2 1回车
则输出
1,2,3,4,5,6,7,8,9,10*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* a, n, i, j, k;
	scanf_s("%d", &n);
	a = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
	}
	for (i = 0; i < n - 1; i++)
	{
		printf("%d,", a[i]);
	}
	printf("%d", a[i]);
	return 0;
}
