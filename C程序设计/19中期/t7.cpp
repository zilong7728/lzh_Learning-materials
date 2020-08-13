#include<stdio.h>
int main()
{
	FILE *f;
	char a[100];
	int m;
	f=fopen("file.txt","r");
	scanf("%d",&m);
	for(int i=0;i<=m;i++)
	{
		fgets(a,99,f);
		printf("%s",a);
	}
	fclose(f);
	return 0;
}
