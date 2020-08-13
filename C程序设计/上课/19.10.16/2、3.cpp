#include<stdio.h>
int main()
{
	char a;
	int b;
	scanf("%c",&a);
	b=(int)a;
	if(((b>=65)&&(b<=90))||((b>=97)&&(b<=122)))
	{
		printf("correct");
	}
	else
	{
		printf("error");
	}
	return 0;
 } 
