#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
	int a,b,c,d,computer=0,human=0;
	srand(time(NULL));
	for(int i=0;i<=9;i++)
	{
		a=rand()%6;
		b=rand()%11;
		scanf("%d %d\n",&c,&d);
		if(b==a+c)
		{
			computer++;		
		}
		else if(d=a+c)
		{
			human++;
		}
	}
	if(computer>human)
	{
		printf("you lose!");
	}
	else if(human>computer)
	{
		printf("you win!");
	}
	else if(computer==human)
	{
		printf("draw!");
	}
	return 0;
} 
