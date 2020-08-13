#include<stdio.h>
typedef struct stu
{
	int ma,ch,en;
}stu;
int main()
{
	stu a[105];
	int n;
	scanf("%d",n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a[i].ma,&a[i].ch,&a[i].en);
	}
	for(int i=1;i<=n;i++)
	{
		printf("student%d:\n",i);
		printf("math:%d\n chinese:%d\n english:%d",a[i].ma,a[i].ch,a[i],en);
	}
	return 0;
}
