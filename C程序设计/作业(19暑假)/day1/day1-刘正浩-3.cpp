/*求圆柱体的表面积和体积*/ 
#include<stdio.h>
#include<stdlib.h>
int main()
{
	float const pi = 3.14;
	float r, h, area, volume;
	scanf_s("%f %f", &r, &h);
	area = pi * (r*r);
	volume = area * h;
	printf("area=%0.2f,volume=%0.2f", area, volume);
	system("pause");
	return 0;
}


