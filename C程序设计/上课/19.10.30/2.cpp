#include<stdio.h>
int main()
{
	int a=100,b,c,d,e;
	while(a<1000)
	{
		b=a%10;
    	c=a%100/10;
    	d=a/100;
    	e=b*b*b+c*c*c+d*d*d;
    	if(e==a)
    	{
    		printf("%d\n",e);
    	}
    	a++;
	}
	return 0;
} 
