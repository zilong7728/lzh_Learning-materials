/*求立方体体积*/ 
#include<stdio.h>
#include<stalib.h>
int volume(int a,int b,int c)
{
	int p;
	p = a * b * c;
	return(p);
}
int main()
{
	int x, y, z, V;
	scanf_s("%d %d %d", &x, &y, &z);
	V = volume(x, y, z);
	printf("V=%d\n", V);
	system("pause");
	return 0;
}
