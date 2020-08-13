#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,delta;
	double x1,x2,k;
	printf("快乐地解一元二次方程\n请按此格式输入a b c\n");
	scanf("%d %d %d",&a,&b,&c);
	delta=b*b*1.0-4*a*c*1.0;
	if(delta<0)
	{
		printf("无解\n你算你妈呢\n△<0你还算\n你数学用他妈屁股学的吧\n傻逼\n给爷爬\n老子不伺候了滚\n");
	}
	else
	{
		k=sqrt(delta);
		a=a*1.0;
		b=b*1.0;
		x1=(0-b+k)/(2*a);
		x2=(0-b-k)/(2*a);
		printf("x1=%lf\nx2=%lf\n真他妈的懒死你个狗逼了\n你初高中老师教你那么多年\n结果你他妈的在这儿使唤老子解方程？\n真你妈没良心\n白学了？全还给老师了?\n这次给你脸\n下次再来老子打爆你的狗头\n",x1,x2);
	}
	return 0; 
 } 
