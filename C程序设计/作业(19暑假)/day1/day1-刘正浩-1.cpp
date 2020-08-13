/*求整数绝对值*/ 
#include<stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	if (a>0)
	   a=a;
	else
	   a=-a;  
    printf("abs=%d\n",a) ;
    return 0;
}
