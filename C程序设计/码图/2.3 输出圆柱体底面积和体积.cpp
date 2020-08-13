/*输入圆柱体半径r和高h，求圆柱体底面积和体积。
要求：
pi=3.14
输入的半径和高是float类型
输出保留小数点后2位精度，先输出底面积，再输出英文逗号，再输出体积结束程序。
测试用例：
输入：
9 12
输出：
area=254.34,volume=3052.08

*/
#include<stdio.h>
int main()
{
	const float pi=3.14;
	float r,h,area,volume;
	scanf("%f %f",&r,&h);
	area=pi*r*r;
	volume=area*h;
	printf("area=%.2f,volume=%.2f",area,volume);
	return 0;
}
	
