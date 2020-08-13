#include<stdio.h>
int main()
{
	double x,a=1.0,n,k=1.0,i,ex=1.0;
	scanf("%lf %lf",&x,&n);
	if(n<0)
	{
		printf("error");
	}
	else
	{
		for(i=1.0;i<=n;i++)
	    {
		a=a*(-1)*x;
		k*=i;
		ex+=a/k;
	    }
	    printf("%.6f",ex);
	}
	return 0;
}
