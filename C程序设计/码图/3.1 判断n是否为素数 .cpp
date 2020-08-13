/*输入一个大于3的整数n，判断它是否为素数。（输出yes/no）
例如，输入4，输出no；
输入7，输出yes。
错误输入，则输出error。所有输出没有回车符号。
*/
#include<stdio.h>
#include<math.h>
int main()
{
	int i,n,d=0;
	double sqrtn;
	scanf("%d",&n);
	
	if(n<3)
	{
	  printf("error");
	} 
	
	else
	{ 
	  sqrtn=sqrt(n*1.0);
	  for(i=2;i<=sqrtn;i++)
	  {
	  	if(n%i==0)
		  {
	  	    d++;
	      }
	  }
	  
	  if(d==0)
	  {
	  	printf("yes");
	  }
	  
	  else
	  {
	  	printf("no");
	  }
	} 
	return 0;
}
	
