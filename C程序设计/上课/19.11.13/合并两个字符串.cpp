#include<stdio.h>
int main()
{
	char s1[50],s2[50],s3[100];
	int i,j;
	i=scanf("%s\n%s",s1,s2);
	if(i<2)
	{
		printf("scanf error\n");
		return -1;
	}
	
	strcpy(s3,s1);
	strcat(s3,s2);
	printf("%s\n",s3);
	return 0; 
}
