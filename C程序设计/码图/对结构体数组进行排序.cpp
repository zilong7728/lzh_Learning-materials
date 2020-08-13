/*对结构体数组进行排序。

题目描述：
struct Person{
　　int no;
　　int age;
　　int height;
}
实现sort方法对结构体数组进行排序。
void sort(Person * array,int n);

根据no从小到大排序；如果no相同则根据age排序；如果age相同，则根据height排序。

注意：
遇到异常情况，输出"error"；否则不要随意输出，会视为错误。
*/
#include<stdio.h>
struct Person
{
	int no;
	int age;
	int height;
};
void sort(struct Person* array, int n)
{
	Person k;
	int i, j;
	if (array == NULL || n <= 0)
	{
		printf("error");
		return;
	}
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
		{
			if (array[i].no > array[j].no)
			{
				k = array[i];
				array[i] = array[j];
				array[j] = k;
			}
			if (array[i].no == array[j].no && array[i].age > array[j].age)
			{
				k = array[i];
				array[i] = array[j];
				array[j] = k;
			}
			if (array[i].no == array[j].no && array[i].age == array[j].age && array[i].height > array[j].height)
			{
				k = array[i];
				array[i] = array[j];
				array[j] = k;
			}
		}
}
int main()
{
	struct Person a[105];
	int n, i;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d%d%d", &a[i].no, &a[i].age, &a[i].height);
	}
	sort(a, n);
	for (i = 0; i < n; i++)
	{
		printf("%d %d %d\n", a[i].no, a[i].age, a[i].height);
	}
	return 0;
}
