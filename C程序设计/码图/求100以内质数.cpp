/*编写一个程序，找出1~100中的所有素数。

输入输出格式要求：
	要求每个数后面都要输出逗号，
	请不要输出其他字符
例如：
输出：2,3,5,  */
#include<stdio.h>
#include<math.h>
int main()
{
	int a = 0, i, j;
	double sqrtn;
	for (i = 2; i <= 100; i++)
	{
		sqrtn = sqrt((double)i);
		for (j = 2; j <= sqrtn; j++)
		{
			if (i % j == 0)
			{
				a++;
			}
		}
		if (a == 0)
		{
			printf("%d,", i);
		}
		a = 0;
	}
	return 0;
}
