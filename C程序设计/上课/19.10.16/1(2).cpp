#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d;
	b=sizeof(a);
	c=pow(2.0,b*8.0-1)-1;
	d=-(c+1);
	printf("%l\t%l",c,d);
	return 0;
 } 
