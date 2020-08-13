#include<stdio.h>
#include<math.h>
int main()
{
	int i,n=1000,d=0;
	double sqrtn;
	for(n=1000;n<=2000;n++) 
	{ 
		sqrtn=sqrt(n*1.0);
		d=0;
		for(i=2;i<=sqrtn;i++)
		{
	  		if(n%i==0)
			{
	  	    	d++;
	    	}
		}
    
		if(d==0)
		{
			printf("%d ",n);
		}
	} 
	return 0;
}
	
